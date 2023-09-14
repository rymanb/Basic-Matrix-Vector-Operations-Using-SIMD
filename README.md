# Basic Matrix/Vector Operations Using SIMD

### Project Description  
- Dot Product calculation between two vectors calculated using v1.x * v2.x + v1.y * v2.y + v1.z * v2.z + v1.2 + v2.2
    - To do this with Simd Dot product loads vectors into float arrays for simd use, then loads into simd registers, multiplies then adds them and stores and returns the result
- Matrix vector multiplation calculated by taking dot product of each row in matrix with the vector and putting it in a resulting vector
- Matrix matrix multiplication goes through each row and col and calculates dot product of their vectors and stores in result.

### Compilers  
- Cover which compilers your application targets
    - [ ] gcc [version]  
    - [ ] clang [version]  
    - [x] msvc/Visual Studio [2022]  
