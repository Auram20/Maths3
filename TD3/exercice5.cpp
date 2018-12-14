srand(time(0));
const int matrixSize = 50;
MatrixXd A = MatrixXd::Random(matrixSize, matrixSize);
A += 10 * MatrixXd::Identity(matrixSize, matrixSize);
VectorXd b = VectorXd::Random(matrixSize);

PartialPivLU<MatrixXd>lu(A);
std::cout << (b- A * lu.solve(b)).norm() << std::endl;
ColPivHouseholderQR<MatrixXd> qr(A);
cout <<n (b-A*qr.solve(b)).norm() <<endl;