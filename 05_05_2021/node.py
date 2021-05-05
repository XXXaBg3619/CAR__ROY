from enum import IntEnum

# You can get the enumeration based on integer value, or make comparison
# ex: d = Direction(1), then d would be Direction.NORTH
# ex: print(Direction.SOUTH == 1) should return False
class Direction(IntEnum):
    NORTH = 1
    SOUTH = 2
    WEST  = 3
    EAST  = 4

# Construct class Node and its member functions
# You may add more member functions to meet your needs
class Node:
    def __init__(self, index=0):
        self.index = index
        # store successor as (Node, direction to node, distance)
        self.Successors = []
        self.Explored = False

    def getIndex(self):
        return self.index

    def getSuccessors(self):
        return self.Successors

    def setSuccessor(self, successor, direction, length=1):
        self.Successors.append((successor, Direction(direction), int(length)))
        #print("For Node {}, a successor {} is set.".format(self.index, self.Successors[-1]))
        return 


    def getDirection(self, nd):
        # TODO : if nd is adjacent to the present node, return the direction of nd from the present node
  # For example, if the direction of nd from the present node is EAST, then return Direction.EAST = 4
  # However, if nd is not adjacent to the present node, print error message and return 0 
        for pnd in self.Successors:
            if pnd[0] == nd.index:
                for i in range(1,5):
                    if Direction(i) == pnd[1]:
                        return i
        print("Error")
        return 0

    def isSuccessor(self, nd):
        for succ in self.Successors:
            if succ[0] == nd: 
                return True
        return False

    def setExplored(self):
        self.Explored = True
    
    def closeExplored(self):
        self.Explored = False
    
    def getExplored(self):
        return self.Explored

    def __str__(self):
        return str(self.index)

    def __repr__(self):
        return str(self.index)
    
    def cleanSuccessor(self):
        self.Successors = []