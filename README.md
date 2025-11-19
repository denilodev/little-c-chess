
# ♟️ Little C Chess
>![chess game](https://github.com/user-attachments/assets/cf046d8d-c176-4e33-8dc7-9620a7d7b59a)
>Simple and small (and probably broken somewhere I didn't found).

Small chess game in terminal. This is a project to practice C and learn how to use header files and
organize the code across multiple files in order to improve readability.

Besides the challenge of implementing the logic for how the pieces move, the goal isn't really to build
a full chess game (although having the bare minimum working it would be nice), and that's why some features
are missing.

## 🖥️ Installation

You'll need GCC installed to compile the C code. Inside the directory, double click the `build.bat` file
or type in the terminal:
```bash
./build.bat
```

Only works in Windows, but if you use Linux I believe you don't even need this section in the first place.

## 🏁 How to play

Usually in terminal chess games the algebraic notation is used to make the moves, but this reveals to be
more challenging than I expected (and beyond the scope of this little project), so a easier way to get the
chosen movement is by using the grid tiles in a file-rank (or column-row) notation.

So to make a move, you type the tile where the moving piece are now and the tile where it goes,
like "c2c4" (that translates to the algebraic notation "e4"), a popular first move that get the pawn in c2
tile and moves it to the c4 tile.

>![c2c4 move](https://github.com/user-attachments/assets/289216c6-e1a4-4c28-9869-cf33d399e11d)
> White pieces are uppercase and Black pieces are lowercase (inspired by Forsyth-Edwards Notation).

Another limitation was the check system, that was not implemented. Because of that, castling ignores
opponent's pieces threats to the king and to win you actually need to capture the opponent's king.

> ![black wins](https://github.com/user-attachments/assets/4af740c9-f5de-4fc4-a9fb-b9a4c3ad1945)
> Checks are completely ignored.

Besides that the game is playable, although some bugs may appear.


## 📚 Sources and inspirations

This project was made on my own, so no tutorials were followed and no AI was used to write the code.
I was having fun trying to recreate the unique movement patterns of each chess piece.
I did get some help to write this README file, though:
- [Banesullivan README guide and template](https://github.com/banesullivan/README)
- [Alena Silverbush blog about using images and gifs in README files](https://medium.com/@alenanikulina0/make-your-readme-better-with-images-and-gifs-b141bd54bff3)

## ✍️ What do I learned from this project

- **Divide and conquer (and make it clear!)**: The biggest advantage of splitting the logic across multiple files is the increase in readability, an important factor to consider
since the majority of development projects (as the majority of human great projects and discoveries) are made by entire teams. Communication is one of our biggest abilities,
so [readability and maintainability is always important](https://stackoverflow.com/questions/183201/should-a-developer-aim-for-readability-or-performance-first) in any
software project. Also, this help myself to understand the code while it grows, even if I am the responsible for certain part of it. So don't rely on your memory,
rely on your ability to understand what other people (including you from the past) intended when they wrote that code.
- **Is just a side project**: I felt that I had achieved my goal after being able to split the game logic across multiple files, but I insisted in try to implement
all the pieces movement, even knowing that I did what I wanted. After that the game logic isn't complete yet, but I realized that I was not studing anymore, and the
worse: I was falling in love for the solutions that I created (even knowing that was no big deal), and this is the reason why I stopped. I know I have a lot to learn,
and is not time to be perfeccionist now. So plan your project, start to code, make researches, learn a lot, "[murder your darling](https://wiki.c2.com/?KillYourDarlings)"
and go to the next project.

<div align="center">
  
![it is just an empty cup](https://y.yarn.co/d06a492f-dd93-4230-9aca-00a05d305e99_text.gif)

</div>
