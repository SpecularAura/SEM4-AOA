#linedlist_ops/sort_ll.py
from .add_ll import AddLinkedList

class LinkedList(AddLinkedList):
    def sort(self):
        current = self.head
        while current.getNext() != None:
            innercurrent = self.head
            while innercurrent.getNext() != None:
                if innercurrent.data > innercurrent.getNext().data:
                    temp = innercurrent.data
                    innercurrent.data = innercurrent.getNext().data
                    innercurrent.getNext().data = temp
                innercurrent = innercurrent.getNext()
            current = current.getNext()
