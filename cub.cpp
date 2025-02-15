#include <iostream>
#include <map>
#define FACE_SIZE 3
//  1  задняя
// 234 левая-верхняя-правая
//  5  передняя
//  6  нижняя

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


  void rotate_matr_90(int matr[FACE_SIZE][FACE_SIZE]){
    int new_matr[FACE_SIZE][FACE_SIZE];
    for (int j = 0; j < FACE_SIZE; j++) {
      for (int k = 0; k < FACE_SIZE; k++) {
        // std::cout << k << FACE_SIZE - 1 - j;
        new_matr[k][FACE_SIZE - 1 - j] = matr[j][k];
      }
    }

    for (int j = 0; j < FACE_SIZE; j++) {
      for (int k = 0; k < FACE_SIZE; k++) {
        matr[j][k] = new_matr[j][k];
      }
    }
  }

  // void rotate_face_with_out_matr(){
  //   std::map<int, int[4]> map;
  //   map[2] = {3, 1, 6, 5};
  //     int swap;
  //     for (int j = 0; j < FACE_SIZE; j++){
  //       for (int k = 0; k < FACE_SIZE; k++){
  //         swap = cub_[3][j][k];
  //         cub_[3][j][k] = cub_[1][j][k];
  //         cub_[1][j][k] = cub_[6][j][k];
  //         cub_[6][j][k] = cub_[5][j][k];
  //         cub_[5][j][k] = swap;
  //       }
  //     }
  // }

  void rotate_left_face_90() {
    rotate_matr_90(cub_[2])
    rotate_face_with_out_matr()
  }

  void rotate_right_face_90() {
      int swap;
      for (int j = 0; j < FACE_SIZE; j++){
        for (int k = 0; k < FACE_SIZE; k++){
          swap = cub_[3][j][k];
          cub_[3][j][k] = cub_[1][j][k];
          cub_[1][j][k] = cub_[6][j][k];
          cub_[6][j][k] = cub_[5][j][k];
          cub_[5][j][k] = swap;
        }
      }
  }

  void rotate_right_face_90() {
    int swap;
      for (int j = 0; j < FACE_SIZE; j++){
        for (int k = 0; k < FACE_SIZE; k++){
          swap = cub_[3][j][k];
          cub_[3][j][k] = cub_[1][j][k];
          cub_[1][j][k] = cub_[6][j][k];
          cub_[6][j][k] = cub_[5][j][k];
          cub_[5][j][k] = swap;
        }
      }
  }
};

int main(int argc, char const *argv[]) {
  Cub cub;
  cub.rotate_face_90(1);
  cub.print();
  return 0;
}
