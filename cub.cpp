#include <iostream>
#include <map>
#define FACE_SIZE 3
//  0  задняя (на физическом кубике - красная)
// 123 левая-верхняя-правая    (белая-зелёная-жёлтая)
//  4  передняя                     (оранжевая)
//  5  нижняя                         (синяя)

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

// private:
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

  void rotate_face_with_out_matr(){
      int swap;
      for (int k = 0; k < FACE_SIZE; k++){
        swap = cub_[4][k][0];
        cub_[4][k][0] = cub_[5][0][FACE_SIZE - k - 1]; 
        cub_[5][0][FACE_SIZE - k - 1] = cub_[0][2][k];
        cub_[0][2][k] = cub_[2][FACE_SIZE - k - 1][2]; 
        cub_[2][FACE_SIZE - k - 1][2] = swap;
      }
  }

  void rotate_right_face_90() {
    rotate_matr_90(cub_[4]);
    rotate_face_with_out_matr();
  }
};

int main(int argc, char const *argv[]) {
  Cub cub;
  cub.rotate_right_face_90();
  cub.print();
  return 0;
}
