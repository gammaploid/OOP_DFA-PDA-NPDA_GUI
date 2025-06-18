# Object-Oriented Automaton Simulator

## Demos

### GUI
![GUI Demo](./Demo/GUIDemo.gif)

### CLI
![CLI Demo](./Demo/CLIDemo.gif)

This project contains a unified C++ object-oriented program that simulates three types of automata:
1.  **Deterministic Finite Automaton (DFA)**
2.  **Pushdown Automaton (PDA)**
3.  **Non-Deterministic Pushdown Automaton (NPDA)**

The program uses object-oriented principles like inheritance and polymorphism to allow the user to choose and run any of the automata from a single menu.

## Compilation

A `Makefile` is provided for easy compilation. To build the simulator, simply run the `make` command:

```bash
make
```

This will create a single executable: `automaton_simulator`.

To remove the compiled executable and object files, you can run:
```bash
make clean
```

## Running the Simulator

To run the simulator, use the following command:
```bash
./automaton_simulator
```
The program will then present a menu where you can choose which automaton to test. The languages recognized are:
- **DFA**: Recognizes L₁ = { w ∈ {0,1} | w contains exactly one occurrence of the symbol '1' }.
- **PDA**: Recognizes L₂ = { 0ⁿ 1ⁿ⁺¹ | n ≥ 0 }.
- **NPDA**: Recognizes L₃ = { w ∈ {0,1} | w = wᴿ } (binary palindromes).

## Project Structure

-   `src/`: Contains the C++ source code.
    -   `Automaton.h`: Abstract base class for all automata.
    -   `DFA.h`, `DFA.cpp`: Implementation of the DFA.
    -   `PDA.h`, `PDA.cpp`: Implementation of the PDA.
    -   `NPDA.h`, `NPDA.cpp`: Implementation of the NPDA.
    -   `main.cpp`: The main entry point, containing the menu and all UI logic.
-   `Makefile`: Compilation script.


## Acknowledgements

This project utilizes the following open-source libraries:

-   [Dear ImGui](https://github.com/ocornut/imgui): A bloat-free graphical user interface library for C++.
-   Inspiration and guidance for using ImGui were drawn from:
    -   [Modern C++ GUI Programming with ImGui](https://alandefreitas.github.io/moderncpp/guis/imgui/)
    -   [Conan 'dear-imgui' Example](https://github.com/conan-io/examples/blob/master/libraries/dear-imgui/basic/main.cpp)
    -   [Moonlight Project](https://github.com/Madam-Herta/Moonlight)
    -   [Conan Examples 2](https://github.com/conan-io/examples2?tab=readme-ov-file)
    -   [ImAlgorithm](https://github.com/fhamonic/imalgorithm)

## License

This project is licensed under the MIT License - see the [LICENSE](LICENSE) file for details.
