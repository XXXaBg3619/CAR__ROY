from node import *
import numpy as np
import csv
import pandas
from enum import IntEnum
import math
from itertools import permutations


class Action(IntEnum):
    ADVANCE = 1
    U_TURN = 2
    TURN_RIGHT = 3
    TURN_LEFT = 4
    HALT = 5
    BACK = 6


class Maze:
    def __init__(self, filepath):
        # TODO : read file and implement a data structure you like
        # For example, when parsing raw_data, you may create several Node objects.  
        # Then you can store these objects into self.nodes.  
        # Finally, add to nd_dictionary by {key(index): value(corresponding node)}
        self.raw_data = pandas.read_csv(filepath).values
        self.nodes = []
        self.nd_dict = dict()  # key: index, value: the correspond node
            
        for i in self.raw_data:
            index = int(i[0])
            node = Node(int(i[0]))
            self.nodes.append(node)
            self.nd_dict[index] = node
        

    def getStartPoint(self):
        if (len(self.nd_dict) < 2):
            print("Error: the start point is not included.")
            return 0
        return self.nd_dict[1]

    def getNodeDict(self):
        return self.nd_dict

    def BFS(self, nd):
        # TODO : design your data structure here for your algorithm
        Adj = dict()
        Q = list()
        Pi = dict()
        D = dict()
        
        Q.append(nd)
        for i in self.nd_dict:
            self.nd_dict[i].closeExplored()
        self.nd_dict[nd].setExplored()
        D[nd] = 0
        for line in self.raw_data:
            counter = 0
            for data in line:
                if counter > 4:
                    continue
                if data == line[0]:
                    index = int(data)
                    Adj[index] = []
                    self.nd_dict[index].cleanSuccessor()
                else :
                    if not data != data:
                        Adj[index].append(int(data))
                        self.nd_dict[index].setSuccessor(int(data), counter, 2)
                counter += 1
        
        while Q:
            presentNode = Q.pop(0)
            adjCounter = 0
            for adjacent in Adj[presentNode]:
                if self.nd_dict[adjacent].getExplored():
                    adjCounter += 1
                    continue
                self.nd_dict[adjacent].setExplored()
                Q.append(adjacent)
                Pi[adjacent] = presentNode
                D[adjacent] = D[presentNode] + 1
            if adjCounter == len(Adj[presentNode]): # if meet a deadend, break
                break
        path = []
        path.append(presentNode)
        while presentNode in Pi:
            presentNode = Pi[presentNode]
            path.append(presentNode)
        path.reverse()
                
                
        # Tips : return a sequence of nodes from the node to the nearest unexplored deadend
        return path

    def BFS_2(self, nd_from, nd_to):
        # TODO : similar to BFS but with fixed start point and end point
        Adj = dict()
        Q = list()
        Pi = dict()
        D = dict()

        Q.append(nd_from)
        for i in self.nd_dict:
            self.nd_dict[i].closeExplored()
        self.nd_dict[nd_from].setExplored()
        D[nd_from] = 0
        for line in self.raw_data:
            counter = 0
            for data in line:
                if counter > 4:
                    continue
                if data == line[0]:
                    index = int(data)
                    Adj[index] = []
                    self.nd_dict[index].cleanSuccessor()
                else :
                    if not data != data:
                        Adj[index].append(int(data))
                        self.nd_dict[index].setSuccessor(int(data), counter, 2)
                counter += 1
            
        while Q:
            presentNode = Q.pop(0)
            if presentNode == nd_to: # if meet the goal, break
                break
            for adjacent in Adj[presentNode]:
                if self.nd_dict[adjacent].getExplored():
                    continue
                self.nd_dict[adjacent].setExplored()
                Q.append(adjacent)
                Pi[adjacent] = presentNode
                D[adjacent] = D[presentNode] + 1
            
        path = []
        path.append(presentNode)
        distance = D[presentNode]
        while presentNode in Pi:
            presentNode = Pi[presentNode]
            path.append(presentNode)
        path.reverse()
        # Tips : return a sequence of nodes of the shortest path
        return path

    def getAction(self, nd_from, nd_to):
        # TODO : get the car action
        # Tips : return an action and the next direction of the car if the nd_to is the Successor of nd_from
        # If not, print error message and return 0
        #if nd_from.isSuccessor(nd_to) == True:
        rel = [self.car_direction, nd_from.getDirection(nd_to)]
        if rel in ([1, 1], [2, 2], [3, 3], [4, 4]):
            print("go straight!")
            dir = 1
        elif rel in ([1, 3], [3, 2], [2, 4], [4, 1]):
            print("turn left!")
            dir = 4
        elif rel in ([1, 4], [4, 2], [2, 3], [3, 1]):
            print("turn right!")
            dir = 3
        elif rel in ([1, 2], [2, 1], [3, 4], [4, 3]):
            print("turn 180")
            dir = 2
        else:
            print("stop!")
            dir = 5
        self.car_direction = nd_from.getDirection(nd_to)
        return dir

    def strategy(self, nd):
        return self.BFS(nd)

    def strategy_2(self, nd_from, nd_to):
        return self.BFS_2(nd_from, nd_to)
    
    def AdjacentDistance(self, nd_from, nd_to):
        for i in range(1, 5):
            if self.raw_data[nd_from - 1][i] == nd_to:
                return self.raw_data[nd_from - 1][i + 4]
    
    def Distance(self, nd_from, nd_to):
        path = self.BFS_2(nd_from, nd_to)
        length = 0
        for i in range(len(path) - 1):
            length += self.AdjacentDistance(path[i], path[i + 1])
        return length
    
    def FindEndNode(self):
        endnode = [1]
        for nd in range(len(self.raw_data)):
            adjnode_num = 0
            for i in self.raw_data[nd][1: 5]:
                if str(i) != "nan":
                    adjnode_num += 1
            if adjnode_num == 1 and nd != 0:
                endnode.append(nd + 1)
        return endnode

    def ShortestPath(self, nd):
        end_nodes = self.FindEndNode()
        all_path = list(permutations(end_nodes[1:], len(end_nodes) - 1))
        print(all_path)
        for i in range(len(all_path)):
            all_path[i] = [nd] + list(all_path[i])
        shortest_distance = 0
        for path in all_path:
            length = 0
            for j in range(len(end_nodes) - 1):
                length += self.Distance(path[j], path[j + 1])
            if shortest_distance == 0 or shortest_distance > length:
                shortest_distance = length
                shortest_endnode_path = path
        shortest_path = []
        for k in range(len(shortest_endnode_path) - 1):
            if shortest_path != []:
                shortest_path.pop(-1)
                shortest_path += self.BFS_2(shortest_endnode_path[k], shortest_endnode_path[k + 1])
            else:
                shortest_path = self.BFS_2(shortest_endnode_path[k], shortest_endnode_path[k + 1])
        self.car_direction = self.nd_dict[nd].getDirection(self.nd_dict[shortest_path[1]])
        return shortest_path