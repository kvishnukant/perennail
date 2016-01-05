package multiply_division_module;

import java.util.NoSuchElementException;

public class DoubleLinklistImplementation <E> {
	private Node head;
    private Node tail;
    private int size;
    
    
    
    public DoubleLinklistImplementation() {
		size=0;
	}




	private class Node {
        E element;
        Node next;
        Node prev;
 
        public Node(E element, Node next, Node prev) {
            this.element = element;
            this.next = next;
            this.prev = prev;
            
        }
    }
    
    
    
    
    public int size() { return size; }

    
    public boolean isEmpty() { return size == 0; }
    
    
    public void addFirst(E element) {
        Node tmp = new Node(element, head, null);
        if(head != null ) {head.prev = tmp;}
        head = tmp;
        if(tail == null) { tail = tmp;}
        size++;
        System.out.println("adding: "+element);
    }
    
    public void iterateForward(){
        
        System.out.println("iterating forward..");
        Node tmp = head;
        while(tmp != null){
            System.out.println(tmp.element);
            tmp = tmp.next;
        }
    }
    
    
    public void addLast(E element) {
        
        Node tmp = new Node(element, null, tail);
        if(tail != null) {tail.next = tmp;}
        tail = tmp;
        if(head == null) { head = tmp;}
        size++;
        System.out.println("adding: "+element);
    }
    
    public E removeFirst() {
        if (size == 0) throw new NoSuchElementException();
        Node tmp = head;
        head = head.next;
        head.prev = null;
        size--;
        System.out.println("deleted: "+tmp.element);
        return tmp.element;
    }
    
    public E removeLast() {
        if (size == 0) throw new NoSuchElementException();
        Node tmp = tail;
        tail = tail.prev;
        tail.next = null;
        size--;
        System.out.println("deleted: "+tmp.element);
        return tmp.element;
    }
    
    public void iterateBackward(){
        
        System.out.println("iterating backword..");
        Node tmp = tail;
        while(tmp != null){
            System.out.println(tmp.element);
            tmp = tmp.prev;
        }
    }
    
    public void addAtPosition(E element, int pos)
    {
    	if(head==null||pos==1)
    	{
    		addFirst(element);
    		return;
    	}
    	Node tmp = new Node(element, head, tail);
    	Node tmpStart=head,tmpPos;
    	while(tmpStart!=null)
    	{
    		if()
    	}
    }
    
     public static void main(String ar[])
     {
    	 DoubleLinklistImplementation<Integer> doubleLink=new DoubleLinklistImplementation<>();
    	 
    	 doubleLink.addFirst(10);
    	 doubleLink.addFirst(20);
    	 doubleLink.addFirst(30);
    	 doubleLink.addLast(40);
    	 doubleLink.addLast(50);
    	 doubleLink.iterateForward();
    	 System.out.println(doubleLink.size());
    	 
     }
}
