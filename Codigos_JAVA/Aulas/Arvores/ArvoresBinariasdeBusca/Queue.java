package ArvoresBinariasdeBusca;

public class Queue {
  private QueueNode front;
  private QueueNode rear;

  public void enqueue(No no) {
      QueueNode newNode = new QueueNode(no);
      if (rear == null) {
          front = rear = newNode;
      } else {
          rear.next = newNode;
          rear = newNode;
      }
  }

  public No dequeue() {
      if (front == null) {
          return null; // Fila vazia
      }
      No removedNo = front.info;
      front = front.next;
      if (front == null) {
          rear = null;
      }
      return removedNo;
  }

  
  public boolean isEmpty() {
      return front == null;
  }

  
  public No peek() {
      if (front == null) {
          return null; // Fila vazia
      }
      return front.info;
  }
}

class QueueNode {
  No info;
  QueueNode next;

  public QueueNode(No info) {
      this.info = info;
      this.next = null;
  }
}