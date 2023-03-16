#priorityqueue.py
class Element:
    def __init__(self, data, priority):
        self.data = data
        self.priority = priority


class Queue:
    def __init__(self):
        self.items = []

    def isEmpty(self):
        return self.items == []

    def enqueue(self, data, priority):
        item = Element(data, priority)
        i = 0
        for listitem in self.items:
            if listitem.priority > item.priority:
                i += 1

        self.items.insert(i,item)

    def dequeue(self):
        return self.items.pop()

    def size(self):
        return len(self.items)