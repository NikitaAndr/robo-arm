#include <iostream>
#define FACE_SIZE 3
// 1  задняя
// 234 левая-верхняя-правая
// 5  передняя
// 6  нижняя

class Cub {
public:
  Cub() { fillCub(); }

  void print() {
    for (int i = 0; i < 6; i++) {
      for (int j = 0; j < FACE_SIZE; j++) {
        for (int k = 0; k < FACE_SIZE; k++) {
          std::cout << cub_[i][j][k] << ", ";
        }
        std::cout << "\n";
      }
      std::cout << "\n";
    }
  }

private:
  int cub_[6][FACE_SIZE][FACE_SIZE];

  void fillCub() {
    for (int i = 0; i < 6; i++) {
      for (int j = 0; j < FACE_SIZE; j++) {
        for (int k = 0; k < FACE_SIZE; k++) {
          cub_[i][j][k] = i * 100 + j * 10 + k;
        }
      }
    }
  }
};

int main(int argc, char const *argv[]) {
  Cub cub;
  cub.print();
  return 0;
}
