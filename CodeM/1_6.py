# -*- coding: utf-8 -*-

#1_6.py
#CodeM Qualifying

'''
Instruction: CodeM - 1_6 围棋
Developer: lrushx
Process Time: June 12, 2017
'''

'''
围棋是起源于中国有悠久历史的策略性棋类游戏。它的规则如下：
1. 棋盘19*19。
2. 棋子分黑白两色，双方各执一色。
3. 下法：每次黑或白着一子于棋盘的空点上。棋子下定后，不再向其他点移动。
4. 棋子的气：一个棋子在棋盘上，与它相邻的空点是这个棋子的“气”（这里相邻是指两个点有公共边）。 相邻的点上如果有同色棋子存在，这些棋子就相互连接成一个不可分割的整体，气合并计算。
相邻的点上如果有异色棋子存在，此处的气便不存在。
如果棋子所在的连通块失去所有的气，即为无气之子，不能在棋盘上存在。
5. 提子：把无气之子清理出棋盘的手段叫“提子”。提子有二种：
1) 着子后，对方棋子无气，应立即提取对方无气之子。
2) 着子后，双方棋子都呈无气状态，应立即提取对方无气之子。
6. 禁着点：棋盘上的任何一空点，如果某方在此下子，会使该子立即呈无气状态，同时又不能提取对方的棋子，这个点叫做“禁着点”，该方不能在此下子。
7. 禁止全局同形：无论哪一方，在成功进行了着子、提子操作后，棋盘局面不能和任何之前的局面相同。

你要做的是：输入一些操作，从空棋盘开始模拟这些操作。
对于每一步，若结果不正确，则输出对应的miss并且忽略这个操作，并在最后输出棋盘的局面。
'''
import sys
import copy

B_size = 19
move = [[0,1],[0,-1],[1,0],[-1,0]]

def search_hash(H,key):
    if key in H:
        return True
    i,j = 0,len(H)-1
    while (i <= j):
        mid = (j - i)/2 + i
        if H[mid][0] < key[0]:
            i = mid + 1
        else:
            j = mid - 1
    H[i:i] = copy.deepcopy([key])
    return False

def grape(lib,g,loc,hash1):
    visit = [[False]*B_size for i in xrange(B_size)]
    color = 3-g[loc[0]][loc[1]]
    hash2 = copy.deepcopy(hash1)
    d_list = []
    for ii in xrange(4):
        x,y = loc[0]+move[ii][0],loc[1]+move[ii][1]
        if (x>=0 and x<B_size and y>=0 and y<B_size and not visit[x][y] and g[x][y] == color and lib[x][y] == 1):
            visit[x][y] = True
            b_list = [[x,y]]
            i,j = -1,0
            while i < j:
                i += 1
                pos = b_list[i]
                d_list.append(pos)
                hash2[pos[0]] -= color*(3**pos[1])
                g[pos[0]][pos[1]] = 0
                for jj in xrange(4):
                    x1,y1 = pos[0]+move[jj][0],pos[1]+move[jj][1]
                    if (x1>=0 and x1<B_size and y1>=0 and y1<B_size and not visit[x1][y1] and g[x1][y1] == color and lib[x1][y1] == 1):
                        visit[x1][y1] = True
                        b_list.append([x1,y1])
                        j += 1
    return hash2,d_list


def updatelib(lib,g,loc,d_list=[]):
    visit = [[False]*B_size for i in xrange(B_size)]
    blank_visit = [[False]*B_size for i in xrange(B_size)]
    visit[loc[0]][loc[1]] = True
    b_list = [loc]                          # b_list = list of points in a block
    color, b_lib = g[loc[0]][loc[1]], 0     # b_lib = liberty of this block

    # update adjecent in same color
    i,j = -1,0
    while i < j:
        i += 1
        pos = b_list[i]
        for ii in xrange(4):
            x1,y1 = pos[0]+move[ii][0],pos[1]+move[ii][1]
            if (x1>=0 and x1<B_size and y1>=0 and y1<B_size and not visit[x1][y1] and g[x1][y1] != 3-color):
                if g[x1][y1] == 0 and not blank_visit[x1][y1]:
                    b_lib += 1
                    blank_visit[x1][y1] = True
                elif g[x1][y1] == color:
                    b_list.append([x1,y1])
                    visit[x1][y1] = True
                    j += 1
    for pos in b_list:
        lib[pos[0]][pos[1]] = b_lib

    # update pos in same color next to those deleted
    for d_pos in d_list:
        for ii in xrange(4):
            x,y = d_pos[0]+move[ii][0],d_pos[1]+move[ii][1]
            if (x>=0 and x<B_size and y>=0 and y<B_size and not visit[x][y] and g[x][y] == color):
                blank_visit = [[False]*B_size for i in xrange(B_size)]
                visit[x][y] = True
                b_list = [[x,y]]    # b_list = list of points in a block
                b_lib = 0           # b_lib = liberty of this block
                i,j = -1,0
                while i < j:        # BFS
                    i += 1
                    pos = b_list[i]
                    for jj in xrange(4):
                        x1,y1 = pos[0]+move[jj][0],pos[1]+move[jj][1]
                        if (x1>=0 and x1<B_size and y1>=0 and y1<B_size and not visit[x1][y1] and g[x1][y1] != 3-color):
                            if g[x1][y1] == 0 and not blank_visit[x1][y1]:
                                b_lib += 1
                                blank_visit[x1][y1] = True
                            elif g[x1][y1] == color:
                                b_list.append([x1,y1])
                                visit[x1][y1] = True
                                j += 1

                for pos in b_list:
                    lib[pos[0]][pos[1]] = b_lib

    # update adjecent in different color, lib-1
    for ii in xrange(4):
        x,y = loc[0]+move[ii][0],loc[1]+move[ii][1]
        if (x>=0 and x<B_size and y>=0 and y<B_size and not visit[x][y] and g[x][y] == 3-color):
            visit[x][y] = True
            b_list = [[x,y]]
            i,j = -1,0
            while i < j:
                i += 1
                pos = b_list[i]
                lib[pos[0]][pos[1]] -= 1
                for jj in xrange(4):
                    x1,y1 = pos[0]+move[jj][0],pos[1]+move[jj][1]
                    if (x1>=0 and x1<B_size and y1>=0 and y1<B_size and not visit[x1][y1] and g[x1][y1] == 3-color):
                        visit[x1][y1] = True
                        b_list.append([x1,y1])
                        j += 1
    return


def printboard(grid):
    for line in grid:
        s = ''
        for pos in line:
            s += '.' if pos == 0 else ('W' if pos == 1 else 'B')
        print s
    return

if __name__ == "__main__":
    # 读取第一行的n
    m = int(sys.stdin.readline().strip())
    for i0 in xrange(m):
        n = int(sys.stdin.readline().strip())
        hasht = [[0]*B_size]
        hash1 = [0]*B_size
        grid  = [[0]*B_size for i in xrange(B_size)]
        lib   = [[0]*B_size for i in xrange(B_size)]
        ## 1=W, 2=B, 0=Blank
        #print len(grid),len(grid[0])
        #print grid
        #miss1 = 0
        for i1 in xrange(n):
            line = sys.stdin.readline().strip()
            op = map(str, line.split())
            # 把第一行的数字分隔后转化成str列表
            x,y = int(op[1])-1,int(op[2])-1
            '''
            if i1 == n-1:
                printboard(grid)
                print op
            '''
            # miss 1, 落子处已经有棋
            if (grid[x][y] > 0):
                print 'miss 1'
                #miss1 += 1
                continue
            color = 1 if op[0] == 'W' else 2    # W = 1, B = 2
            liberty = 0
            neighb = 0
            grapes = 0    # 提子邻居数
            forbid = True
            for ii in xrange(4):
                x1,y1 = x+move[ii][0],y+move[ii][1]
                if (x1>=0 and x1<B_size and y1>=0 and y1<B_size):
                    neighb += 1
                    if grid[x1][y1] == 0:
                        liberty += 1
                    if grid[x1][y1]==3-color and lib[x1][y1] == 1:
                        grapes += 1
                        forbid = False
                    if grid[x1][y1]==color and lib[x1][y1] != 1:
                        forbid = False

            #print 'grid\n',grid
            #print 'liberty\n',lib
            #print 'hash table\n',hasht

            # miss 2，落子处气为0且四周所有同色气==1且所有异色气!=1时，此处为禁着点
            if liberty == 0 and forbid:
                print 'miss 2'
                continue

            # 以下为可以落子，更新临时棋盘
            add_on_hash = color*(3**y)
            # 落子处不与其他棋子相邻，直接落子
            if liberty == neighb:
                hash1[x] += add_on_hash
                if search_hash(hasht,hash1):
                    hash1[x] -= add_on_hash
                    print 'miss 3'
                    continue
                grid[x][y] = color
                lib[x][y]  = liberty
                #print '\n'
                #print lib
                #print op
                #printboard(grid)
                continue

            # grapes为空，不可提子，只更新周边位置的气，同色连通+liberty-1，异色连通-1
            if (grapes == 0):
                #print 'grapes == 0'
                #print hasht
                #print hash1
                hash1[x] += add_on_hash
                #print hasht
                #print hash1
                if search_hash(hasht,hash1):
                    print 'miss 3'
                    #print hasht
                    #print hash1
                    hash1[x] -= add_on_hash
                    continue
                grid[x][y] = color
                updatelib(lib,grid,[x,y],[])
                #print '\n grape=0 \n'
                #print lib
                #print op
                #printboard(grid)
                continue

            # grapes非空，说明可以提子
            if (grapes > 0):
                g = copy.deepcopy(grid)
                g[x][y] = color
                hash1[x] += add_on_hash
                hash2,d_list = grape(lib,g,[x,y],hash1)
                #print 'inner hash'
                #print hasht
                #print hash1
                #print hash2
                if search_hash(hasht,hash2):
                    print 'miss 3'
                    hash1[x] -= add_on_hash
                    continue
                hash1 = copy.deepcopy(hash2)
                grid = copy.deepcopy(g)
                updatelib(lib,grid,[x,y],d_list)
                #print 'grape #:', len(d_list)
                #print '\ngrape'
                #print lib
                #print op
                #printboard(grid)
        #print grid
        #print miss1
        print hash1
        printboard(grid)
