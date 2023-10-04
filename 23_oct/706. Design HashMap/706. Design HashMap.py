class MyHashMap:

    def __init__(self):
        self.keys = []
        self.values = []

    def key_idx(self, k): 
        for i in range(len(self.keys)): 
            if self.keys[i]==k: 
                return i
        return -1
    def put(self, key: int, value: int) -> None:
        v = self.key_idx(key)
        if v==-1: 
            self.keys.append(key)
            self.values.append(value)
        else : 
            self.values[v] = value

    def get(self, key: int) -> int:
        v = self.key_idx(key)
        if v==-1: 
            return -1
        else : 
            return self.values[v]

    def remove(self, key: int) -> None:
        idx = self.key_idx(key)
        if idx==-1: 
            return 
        self.keys.pop(idx)
        self.values.pop(idx)


# Your MyHashMap object will be instantiated and called as such:
# obj = MyHashMap()
# obj.put(key,value)
# param_2 = obj.get(key)
# obj.remove(key)
