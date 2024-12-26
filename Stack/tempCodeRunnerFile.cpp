 main()
{
    Stack<char> operators;
    char exp[8] = "a+b*c-d";
    char postexp[8];
    int k = 0;
    for (int i = 0; i < 7; i++)
    {
        if (! operato(exp[i]))
        {
            postexp[k] = exp[i];
            k++;
        }
        else
        {
            if (operators.length() == 0 || prec(operators.peek()) <= prec(exp[i]))
            {
                operators.push(exp[i]);
            }
            else if (prec(operators.peek()) > prec(exp[i]))
            {
                while (operators.length() != 0)
                {
                    postexp[k] = operators.peek();
                    operators.pop();
                    k++;
                    
                }
                operators.push(exp[i]);
            }
        }
    }
    while (operators.length() != 0)
    {
        postexp[k] = operators.peek();
        operators.pop();
        k++;
    }
    cout<<postexp;
}