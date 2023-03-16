from linkedlist_ops import LinkedList
from linkedlist_ops import SampleLinkedList
from stack_app import in_pre, post_eval
from .priorityqueue import Queue
mylist = SampleLinkedList()

mylist.sort()
print(mylist.add_list())
mylist.print_ll()

print(in_pre("( A - B / C ) * ( A / K - L )"))
print(post_eval("1 2 3 + -"))

#Priority Queue Driver
q=Queue()
print("Inserting 3 elements")
q.enqueue(4, 1)
q.enqueue('dog', 2)
q.enqueue(True, 1)
print("Queue Size: %d" % q.size())
print("Queue Empty :", q.isEmpty())
q.enqueue(8.4, 1)
print("Insert one more element")
print(f'First Element: {q.dequeue()}')
print(f'Second Element: {q.dequeue()}')
print("After dequeue two elements")
print("Queue size :",q.size())