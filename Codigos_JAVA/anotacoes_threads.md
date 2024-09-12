### 1. **Threads**
Em Java, uma **thread** é uma unidade de execução que pode rodar em paralelo com outras threads. Cada programa Java tem pelo menos uma thread principal, e você pode criar threads adicionais para realizar tarefas simultâneas.

**Exemplo de Criando uma Thread:**

Existem duas maneiras principais de criar threads em Java:

- **Implementando a interface `Runnable`**
- **Estendendo a classe `Thread`**

**Exemplo com Runnable:**

```java
class MyRunnable implements Runnable {
    public void run() {
        System.out.println("Thread is running...");
    }
}

public class Main {
    public static void main(String[] args) {
        // Criando uma instância de MyRunnable
        MyRunnable runnable = new MyRunnable();

        // Criando uma thread e passando a instância de MyRunnable para ela
        Thread thread = new Thread(runnable);

        // Iniciando a execução da thread
        thread.start();
    }
}
```

**Exemplo com Thread:**

```java
class MyThread extends Thread {
    public void run() {
        System.out.println("Thread is running...");
    }
}

public class Main {
    public static void main(String[] args) {
        // Criando uma instância da MyThread
        MyThread thread = new MyThread();

        // Iniciando a execução da thread
        thread.start();
    }
}
```

### 2. **Métodos Importantes para Threads**

- `start()`: Inicia a execução da thread. O método `run()` é chamado quando a thread começa a ser executada.
- `run()`: Contém o código que será executado pela thread. Você pode sobrescrever esse método ao estender `Thread` ou implementar `Runnable`.
- `sleep(long millis)`: Faz com que a thread atual pause sua execução por um determinado tempo (em milissegundos).
- `join()`: Aguarda a conclusão de uma thread antes de continuar a execução do código subsequente.
- `interrupt()`: Interrompe uma thread, sinalizando que ela deve parar de executar.

**Exemplo de `sleep()` e `join()`:**

```java
class MyThread extends Thread {
    public void run() {
        for (int i = 1; i <= 5; i++) {
            System.out.println(i);
            try {
                Thread.sleep(1000);  // Pausa por 1 segundo
            } catch (InterruptedException e) {
                System.out.println("Thread interrupted");
            }
        }
    }
}

public class Main {
    public static void main(String[] args) {
        MyThread thread = new MyThread();
        thread.start();

        try {
            thread.join();  // Aguarda a conclusão da thread
        } catch (InterruptedException e) {
            System.out.println("Main thread interrupted");
        }

        System.out.println("Main thread finished");
    }
}
```

### 3. **Concorrência e Sincronização**

Quando várias threads acessam o mesmo recurso compartilhado (como uma variável ou um objeto), pode ocorrer **condições de corrida** (race conditions), que podem causar resultados inesperados. Para evitar esses problemas, o Java oferece **sincronização**.

- **Synchronized Methods**: Um método `synchronized` garante que apenas uma thread possa executá-lo por vez em um determinado objeto.
  
  ```java
  public synchronized void method() {
      // Código que apenas uma thread pode acessar por vez
  }
  ```

- **Synchronized Blocks**: Você também pode sincronizar blocos específicos de código para limitar o escopo da sincronização.
  
  ```java
  public void method() {
      synchronized (this) {
          // Código sincronizado
      }
  }
  ```

**Exemplo de Sincronização:**

```java
class Counter {
    private int count = 0;

    public synchronized void increment() {
        count++;
    }

    public int getCount() {
        return count;
    }
}

class MyThread extends Thread {
    Counter counter;

    MyThread(Counter counter) {
        this.counter = counter;
    }

    public void run() {
        for (int i = 0; i < 1000; i++) {
            counter.increment();
        }
    }
}

public class Main {
    public static void main(String[] args) throws InterruptedException {
        Counter counter = new Counter();
        
        MyThread t1 = new MyThread(counter);
        MyThread t2 = new MyThread(counter);
        
        t1.start();
        t2.start();
        
        t1.join();
        t2.join();
        
        System.out.println("Final count: " + counter.getCount());
    }
}
```

### 4. **Estados de uma Thread**

As threads em Java podem estar em diferentes estados durante o seu ciclo de vida:

1. **NEW**: A thread foi criada, mas ainda não foi iniciada (`start()` não foi chamado).
2. **RUNNABLE**: A thread está pronta para ser executada e está aguardando a CPU.
3. **BLOCKED**: A thread está esperando para adquirir um bloqueio de monitor para entrar em um bloco sincronizado.
4. **WAITING**: A thread está aguardando indefinidamente por outra thread para realizar uma ação.
5. **TIMED_WAITING**: A thread está aguardando por um período de tempo específico.
6. **TERMINATED**: A thread completou sua execução.

### Resumo

- **Threads**: Unidades de execução paralelas.
- **Runnable vs Thread**: Duas maneiras de criar threads.
- **Métodos Importantes**: `start()`, `run()`, `sleep()`, `join()`, `interrupt()`.
- **Sincronização**: Evita problemas de concorrência com `synchronized` blocks ou métodos.
- **Estados de Thread**: NEW, RUNNABLE, BLOCKED, WAITING, TIMED_WAITING, TERMINATED.