# LLD Examples

## Table of Contents

- [1.1 TicTacToeGame](#11-TicTacToeGame)


### 1 TicTacToeGame
Design Tic-Tac-Toc game. With multiple player, dynamic and multiple sign.

<details>
  <summary>Tic-Tac-Toc</summary>
  ```js
  
    enum PicesType {
      X = "X",
      O = "O",
    }

    class Queue<T> {
      queue: T[] = [];
      push(item: T) {
        this.queue.push(item);
      }
      pop(): T {
        return this.queue.shift()!;
      }
      front(): T {
        return this.queue[0];
      }
    }
    
    class PlayingPiece {
      pieceType: PicesType;
      constructor(type: PicesType) {
        this.pieceType = type;
      }
    }
    
    class PieceX extends PlayingPiece {
      constructor() {
        super(PicesType.X);
      }
    }
    
    class PieceO extends PlayingPiece {
      constructor() {
        super(PicesType.O);
      }
    }
    
    class PieceFactory {
      instance: PlayingPiece;
      constructor(type: string) {
        // super('');
        if (type === "O") {
          this.instance = new PieceO();
        } else if (type === "X") {
          this.instance = new PieceX();
        } else {
          this.instance = new PieceX();
        }
      }
      getInstance(): PlayingPiece {
        return this.instance;
      }
    }
    
    class Palyer {
      name: string;
      pieceType: PlayingPiece;
      constructor(name: string, pieceType: PlayingPiece) {
        this.name = name;
        this.pieceType = pieceType;
      }
    }
    
    class Board {
      size: number;
      board: PlayingPiece[][] = [];
      constructor(size: number) {
        this.size = size;
        for (let i = 0; i < size; i++) {
          this.board.push(new Array(size).fill(null));
        }
      }
    
      addPiece(r: number, c: number, piece: PlayingPiece): boolean {
        if (this.board[r][c] !== null) return false;
        this.board[r][c] = piece;
        return true;
      }
    
      hasFreeSpace(): boolean {
        return this.board.some((row) => row.some((cell) => cell === null));
      }
    
      printBoard(): void {
        this.board.forEach((row) => {
          console.log(row.map((cell) => cell?.pieceType || "").join(", "));
        });
      }
    
      isThereWinner(r: number, c: number, piece: PlayingPiece): boolean {
        let row = true,
          col = true,
          dia = true,
          anti = true;
        for (let i = 0; i < this.size; i++) {
          if (row && this.board[r][i] !== piece) row = false;
        }
    
        for (let i = 0; i < this.size; i++) {
          if (col && this.board[i][c] !== piece) col = false;
        }
    
        for (let i = 0, j = 0; i < this.size && j < this.size; i++, j++) {
          if (dia && this.board[i][j] !== piece) dia = false;
        }
    
        for (let i = 0, j = this.size - 1; i < this.size && j > -1; i++, j--) {
          if (anti && this.board[i][j] !== piece) anti = false;
        }
        return row || col || dia || anti;
      }
    }
    
    class Game {
      players: Queue<Palyer> = new Queue();
      board: Board;
    
      constructor(size: number, arr: { name: string; piece: string }[]) {
        arr.forEach((player) => {
          const instance = new PieceFactory(player.piece);
          console.log("===", instance.instance);
          this.players.push(new Palyer(player.name, instance.getInstance()));
        });
        this.board = new Board(size);
      }
    
      startGame(): void {
        let noWinner = true;
        while (noWinner) {
          const front: Palyer = this.players.front();
          if (!this.board.hasFreeSpace()) {
            noWinner = false;
            continue;
          }
          this.board.printBoard();
    
          const [r, c]: [number, number] = this.getUserInput(front.name);
          console.log("=== ", r, c, front.pieceType.pieceType);
          const isValidMove: boolean = this.board.addPiece(r, c, front.pieceType);
          if (!isValidMove) {
            console.log("Try again ", front.name, "\n");
            continue;
          }
    
          if (this.board.isThereWinner(r, c, front.pieceType)) {
            console.log("Winner: ", front.name);
            return;
          }
          this.players.pop();
          this.players.push(front);
        }
        console.log("Game is tie");
        return;
      }
    
      getUserInput(name: string): [number, number] {
        const [r, c]: number[] = prompt(`Please take your tern ${name}: `)!
          .split(",")
          .map((i) => +i);
        return [r, c];
      }
    }
    
    const game = new Game(3, [
      { name: "sam", piece: "O" },
      { name: "tom", piece: "X" },
    ]);
    game.startGame();

  ```

</details>
