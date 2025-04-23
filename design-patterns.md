
# SOLID
- S: Single responsibility principles (Only one reasone to change)
- O: Open/Close principles  (Open for extenstion, close for modification)
- L: Liskov substitution principles (should extend functioality of parent class, not narrow it down)
- I: Interface segmented principle (add only nessasery method in interface, devide interface in segment)
- D: Depennacy inversion principle (depend on interface, not on class)

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

## Structural patterns 

### Decorator 
```
   
   abstract class BasePizza {
	public abstract cost(): number;
}

abstract class Toping extends BasePizza {}

class MargaritaPizaa extends BasePizza {
	override cost(): number {
		return 200;
	}
}

class FarmhousePizaa extends BasePizza {
	override cost(): number {
		return 200;
	}
}

class ExtraChess extends Toping {
	basePizaa: BasePizza;
	constructor(base: BasePizza) {
		super();
		this.basePizaa = base;
	}
	cost() {
		return this.basePizaa.cost() + 20;
	}
}

class Mashrooms extends Toping {
	basePizaa: BasePizza;
	constructor(base: BasePizza) {
		super();
		this.basePizaa = base;
	}
	cost() {
		return this.basePizaa.cost() + 40;
	}
}


const pizza = new Mashrooms(new ExtraChess(new MargaritaPizaa()));

console.log('Price: ', pizza.cost())
```

