#linedlist_ops/add_ll.py
from .linkedlist import BaseLinkedList

class AddLinkedList(BaseLinkedList):
    def add_list(self):
        current = self.head
        sum = 0
        while current != None:
            sum = sum + current.getData()
            current = current.getNext()
        
        return sum;