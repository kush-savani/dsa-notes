# SOLID

- S: Single responsibility principles (Only one reason to change)
- O: Open/Close principles (Open for extension, close for modification)
- L: Liskov substitution principles (should extend functionality of parent class, not narrow it down)
- I: Interface segmented principle (add only nessasery method in interface, divide interface in segment)
- D: Dependency inversion principle (depend on interface, not on class)

# Types

1. Creational patterns
2. Structural patterns
3. Behavioral patterns

<img width="1354" alt="Screenshot 2025-04-22 at 11 05 51 PM" src="https://github.com/user-attachments/assets/0c2d5090-3629-4634-a210-dfa29ff2bf15" />
Ref: https://refactoring.guru/design-patterns/catalog

## Creational patterns

### Singleton

- Has only one instance globally
- The Singleton pattern disables all other means of creating objects of a class except for the special creation method. This method either creates a new object or returns an existing one if it has already been created.
  Ex: 1. Single database object shared by different parts of the program.

<img width="1727" alt="Screenshot 2025-04-23 at 9 35 53 AM" src="https://github.com/user-attachments/assets/d1c350ce-8650-40c9-8a9a-82b20cf9e96c" />

### Factory design

<img width="470" alt="Screenshot 2025-04-23 at 10 07 05 AM" src="https://github.com/user-attachments/assets/da61d255-c72f-4be5-9d16-39670b7b75a3" />
<img width="1305" alt="Screenshot 2025-04-23 at 9 47 39 AM" src="https://github.com/user-attachments/assets/4b09036c-4ec3-46ad-9d36-4da23d6555cd" />

## Behavioral patterns

### Strategy

### Observer

Ex: Implement "Notify me" functionality. Assume Amazon product is out of stock, screen have 'Notify me' button. user can click on it. once stock increase, all the subscriber should receive notifications.

```
interface IObserver {
    update: () => void;
}
interface IObservable {
    observerList: IObserver[];
    qty: number;
    item: string;
    add: (obj: IObserver) => void;
    remove: (obj: IObserver) => void;
    notifyMe: () => void;
    setData: (data: number) => void;
    getData: () => string;
}
class Observable implements IObservable {
    observerList: IObserver[] = [];
    qty = 0;
    item = '';
    constructor(item: string) {this.item = item}

    add(obj: IObserver) {this.observerList.push(obj);}

    remove(obj: IObserver) { this.observerList.pop();}

    notifyMe() {
        this.observerList.forEach(obj => obj.update());
    }

    setData(data: number) {
        if(this.qty === 0) {
            this.notifyMe();
        }
        this.qty = data;
    }

    getData() {
        return this.item;
    }
}

class MobileObserver implements IObserver {
    observable: Observable;
    constructor(obj: Observable) {
        this.observable = obj;
    }
    update() {
        console.log('Notified for' + this.observable.getData() + ' on mobile');
    }
}

class EmailObserver implements IObserver {
    observable: Observable;
    constructor(obj: Observable) {
        this.observable = obj;
    }
    update() {
        console.log('Notified for' + this.observable.getData() + ' on email');
    }
}

const iphone = new Observable('iphone');
// const laptop = new Observable('laptop');

const user1 = new MobileObserver(iphone);
const user2 = new EmailObserver(iphone);
const user3 = new MobileObserver(iphone);

iphone.add(user1);
iphone.add(user2);
iphone.add(user3);

iphone.setData(2);
```

## Structural patterns

### Decorator

Ex: Implement pizza cost calculator.

```

abstract class BasePizza {
	public abstract cost(): number;
}

abstract class Toping extends BasePizza {}

class MargaritaPizza extends BasePizza {
	override cost(): number {
		return 200;
	}
}

class FarmhousePizza extends BasePizza {
	override cost(): number {
		return 200;
	}
}

class ExtraChess extends Toping {
	basePizza: BasePizza;
	constructor(base: BasePizza) {
		super();
		this.basePizza = base;
	}
	cost() {
		return this.basePizza.cost() + 20;
	}
}

class Mushrooms extends Toping {
	basePizza: BasePizza;
	constructor(base: BasePizza) {
		super();
		this.basePizza = base;
	}
	cost() {
		return this.basePizza.cost() + 40;
	}
}


const pizza = new Mushrooms(new ExtraChess(new MargaritaPizza()));

console.log('Price: ', pizza.cost())
```
