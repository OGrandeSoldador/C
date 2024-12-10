
struct Delta{
    float A;
    float B;
    float C;
    float D;
};

struct Bhaskara{
    float X1;
    float X2;
    float XV;
    float YV;
};

struct Delta FuncSecDegr;
struct Bhaskara FuncBhask;

struct Delta Receive_ValFunc(struct Delta*)
{
    printf("Passe os Valores para calcular a função de segundo grau:\n");

    printf("Valor de A: ");
    scanf("%f", &FuncSecDegr.A);

    printf("Valor de B: ");
    scanf("%f", &FuncSecDegr.B);

    printf("Valor de C: ");
    scanf("%f", &FuncSecDegr.C);

    return FuncSecDegr;
}

struct Delta Solve_Delta(struct Delta*)
{
    FuncSecDegr.D = (FuncSecDegr.B * FuncSecDegr.B)-4 * FuncSecDegr.A * FuncSecDegr.C;
    printf("O valor de Delta: %.2f",FuncSecDegr.D);
    return FuncSecDegr;
}

struct Bhaskara Solve_X(struct Delta,struct Bhaskara*)
{
    FuncBhask.X1 = (((sqrt(FuncSecDegr.D)) + (-FuncSecDegr.B)) / (2 * FuncSecDegr.A));
    FuncBhask.X2 = ((-(sqrt(FuncSecDegr.D)) + (-FuncSecDegr.B)) / (2 * FuncSecDegr.A));
    printf("\nO valor de X1: %.2f", FuncBhask.X1);
    printf("\nO valor de X2: %.2f", FuncBhask.X2);

    return FuncBhask;
}

struct Bhaskara Solve_Vert(struct Delta,struct Bhaskara*)
{
    FuncBhask.XV = (-FuncSecDegr.B / (2 * FuncSecDegr.A));
    FuncBhask.YV = (-FuncSecDegr.D / (4 * FuncSecDegr.A));
    printf("\nO valor de X Vertice: %.2f", FuncBhask.XV);
    printf("\nO valor de Y Vertice: %.2f", FuncBhask.YV);

    return FuncBhask;
}


int main()
{
    Receive_ValFunc(&FuncSecDegr);
    Solve_Delta(&FuncSecDegr);
    Solve_X(FuncSecDegr,&FuncBhask);
    Solve_Vert(FuncSecDegr,&FuncBhask);

    return 0;
}

