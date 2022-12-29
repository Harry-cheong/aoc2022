class Node:
    def __init__(self, size=0, label="", par=None):
        # actually label is useless but can use for debugging
        self.size = size
        self.label = label
        self.children = {}
        self.par = par

# process each line of file, return node that u shld move to (if not current node)
def process(s, curNode):
    words = s.split()
    # cd command (words = ["$", "cd", actual dir])
    if len(words) == 3:
        # parent
        if words[-1] == "..":
            return curNode.par
        else:
            return curNode.children[words[2]]
    # ls command
    elif s[0] == "$":
        return curNode
    # listed file / directory
    else:
        # initialise child node
        if words[0] == "dir":
            newNode = Node(label=words[1], par=curNode)
        else:
            newNode = Node(size=int(words[0]), label=words[1], par=curNode)
        
        # add to children dictionary
        curNode.children[words[1]] = newNode
        return curNode

ans = 0
def traverse(root):
    global ans
    # base case: normal file / empty directory
    if len(root.children) == 0:
        return root.size
    else:
        size = 0
        for k, v in root.children.items():
            # add subdirectory / subfile to current size
            size += traverse(v)
        root.size = size
        
        # add to ans if applicable
        if root.size <= 100000:
            ans += root.size  
        
        # return size of directory
        return root.size

        
rootNode = Node(label="/")
curNode = rootNode
with open("aoc/dec7.txt", "r") as f:
    next(f)  # skip first row
    for row in f:
        curNode = process(row, curNode)

traverse(rootNode)
print(ans)
