### 1. **Classes**
Uma **classe** em Java é um modelo (ou blueprint) que define a estrutura de um objeto. Ela pode conter atributos (variáveis) e métodos (funções). Uma classe é como uma planta baixa de uma casa: ela define o que a casa (objeto) terá, mas não é a casa em si.

**Exemplo de Classe:**

```java
public class Car {
    // Atributos (variáveis)
    String color;
    String model;
    int year;

    // Métodos (funções)
    void startEngine() {
        System.out.println("The engine is starting...");
    }

    void drive() {
        System.out.println("The car is driving...");
    }
}
```

### 2. **Atributos**
Os **atributos** são variáveis que armazenam o estado de um objeto. Eles são definidos dentro de uma classe e cada objeto criado a partir dessa classe terá seus próprios valores para esses atributos.

**Exemplo de Atributos:**

No exemplo acima, `color`, `model`, e `year` são atributos da classe `Car`. Cada carro (objeto) terá sua própria cor, modelo e ano.

### 3. **Métodos**
Os **métodos** são funções que definem o comportamento de um objeto. Eles podem manipular os atributos e realizar operações específicas.

**Exemplo de Métodos:**

No exemplo acima, `startEngine()` e `drive()` são métodos da classe `Car`. Eles definem o que o carro pode fazer (ligar o motor e dirigir).

### 4. **Objetos**
Um **objeto** é uma instância de uma classe. Quando criamos um objeto, estamos criando uma "cópia" da classe com valores específicos para os atributos.

**Exemplo de Criação de Objetos:**

```java
public class Main {
    public static void main(String[] args) {
        // Criando um objeto da classe Car
        Car myCar = new Car();

        // Definindo valores para os atributos
        myCar.color = "Red";
        myCar.model = "Ferrari";
        myCar.year = 2023;

        // Chamando métodos no objeto
        myCar.startEngine();  // Saída: The engine is starting...
        myCar.drive();        // Saída: The car is driving...

        // Imprimindo os valores dos atributos
        System.out.println("Car Model: " + myCar.model); // Saída: Car Model: Ferrari
        System.out.println("Car Color: " + myCar.color); // Saída: Car Color: Red
        System.out.println("Car Year: " + myCar.year);   // Saída: Car Year: 2023
    }
}
```

### Resumo

- **Classe**: Define a estrutura do objeto (ex.: `Car`).
- **Atributos**: Variáveis que representam o estado do objeto (ex.: `color`, `model`, `year`).
- **Métodos**: Funções que definem o comportamento do objeto (ex.: `startEngine()`, `drive()`).
- **Objeto**: Uma instância da classe com valores específicos para os atributos (ex.: `myCar`).