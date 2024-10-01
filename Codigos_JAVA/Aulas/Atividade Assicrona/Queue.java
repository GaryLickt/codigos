
public class Queue {
  private QueueARBNodede front;
  private QueueARBNodede rear;

  public void enqueue(ARBNode ARBNode) {
      QueueARBNodede newARBNodede = new QueueARBNodede(ARBNode);
      if (rear == null) {
          front = rear = newARBNodede;
      } else {
          rear.next = newARBNodede;
          rear = newARBNodede;
      }
  }

  public ARBNode dequeue() {
      if (front == null) {
          return null; // Fila vazia
      }
      ARBNode removedARBNode = front.info;
      front = front.next;
      if (front == null) {
          rear = null;
      }
      return removedARBNode;
  }

  
  public boolean isEmpty() {
      return front == null;
  }

  
  public ARBNode peek() {
      if (front == null) {
          return null; // Fila vazia
      }
      return front.info;
  }
}