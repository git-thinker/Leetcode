#
# @lc app=leetcode.cn id=208 lang=python3
#
# [208] 实现 Trie (前缀树)
#

# @lc code=start
class Node:
    def __init__(self, char:str = '#', end:bool = False):
        self.val = char[0]
        self.children = {}
        self.end = end
    
    def addNode(self, node):
        self.children[node.val] = node


class Trie:

    def __init__(self):
        """
        Initialize your data structure here.
        """
        self.root = Node(' ')
    

    def insert(self, word: str) -> None:
        """
        Inserts a word into the trie.
        """
        ret, proot, length = self.find(word)
        if ret:
            return None
        elif not length:
            proot.end = True
        else:
            toAddWord = word[-length:]
            for i, char in enumerate(toAddWord):
                tmpNode = Node(char, i == len(toAddWord) - 1)
                proot.addNode(tmpNode)
                proot = tmpNode

    def search(self, word: str) -> bool:
        """
        Returns if the word is in the trie.
        """
        return self.find(word)[0]

    def startsWith(self, prefix: str) -> bool:
        """
        Returns if there is any word in the trie that starts with the given prefix.
        """
        return self.find(prefix)[-1] == 0

    def find(self, word: str):
        length = len(word)
        proot = self.root
        for i, char in enumerate(word):
            each = proot.children.get(char, None)
            if each is not None:
                proot = each
                length -= 1
            else:
                break

        return (not length) and (proot.end), proot, length

# Your Trie object will be instantiated and called as such:
# obj = Trie()
# obj.insert(word)
# param_2 = obj.search(word)
# param_3 = obj.startsWith(prefix)
# @lc code=end

