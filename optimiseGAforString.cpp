#include "getStringCode.hpp"

#define POPULATION_SIZE 20
#define INPUT_STRINGS 25
typedef struct
{
    int optimiserPopulation;
    float optimiserMutation;
    float optimiserAverage;
}optimize;

optimize population[POPULATION_SIZE];
string inputStrings[INPUT_STRINGS];

main()
{
    //to seed random number generation
	srand((unsigned)(time(0)));

    //create getStringCode object
    Individual getString;
    cout << "Generating Strings:\n";
    //generate input strings
    for(int i = 0; i < INPUT_STRINGS; i++)
    {
        int len = random_num(0, 15);
        inputStrings[i] = create_gnome(len);
        cout << inputStrings[i] << "\n";
    }

    //generate initial (random) optimizer values
    for(int i =  0; i < POPULATION_SIZE; i++)
    {
        population[i].optimiserPopulation = random_num(100, 5000);
        population[i].optimiserMutation = 0.1;
        population[i].optimiserAverage = 301;
    }

    int numberOfIterations = 0;
    while(population[0].optimiserAverage > 10)
    {
        cout << "Generation # "<< numberOfIterations <<"\n";
        numberOfIterations++;
        for(int i = 0; i < POPULATION_SIZE; i++)
        {
            cout << "Population # "<< i <<"\n";

            //zero the last average before starting new calculations
            population[i].optimiserAverage = 0;
            for(int j = 0; j < INPUT_STRINGS; j++)
            {
                cout << "Generating " << i <<"th string\n";
                TARGET = inputStrings[j];
                population[i].optimiserAverage += getString.getTargetString(
                population[i].optimiserPopulation,
                population[i].optimiserMutation);
            }
            population[i].optimiserAverage /= INPUT_STRINGS;
//            cout << "Average is: "<< population[i].optimiserAverage <<
  //              "\n";
        }

        //sort the population in ascending order for optimiserAverage
        for(int i = 0; i < POPULATION_SIZE; i++)
        {
            for(int j = i + 1; j < (POPULATION_SIZE - 1);j++)
            {
                if(population[i].optimiserAverage >
                    population[j].optimiserAverage)
                {
                    float temp = population[j].optimiserAverage;
                    population[j].optimiserAverage =
                    population[i].optimiserAverage;
                    population[i].optimiserAverage = temp;
                }
            }
        }
        //mutate all the 60% population at the bottom...
        ////retain the top 40% good performing population...
        int mutationPercent = POPULATION_SIZE * 0.4;
        int maxLimit = POPULATION_SIZE - mutationPercent;
        for(int i = mutationPercent; i < maxLimit; i++)
        {
            int randomIncrement = random_num(0,100);
            population[i].optimiserPopulation +=
                (population[i].optimiserPopulation * randomIncrement);

            float randomProbabilityInc = random_probability();
            population[i].optimiserMutation += randomProbabilityInc;

            while(population[i].optimiserMutation >= 1)
            {
                population[i].optimiserMutation = random_probability();
            }
        }
    }
    cout << "Best average is: \t " <<
        population[0].optimiserAverage << "\n"<<
        "With Population Size: \t " <<
        population[0].optimiserPopulation << "\n"<<
        "With Mutation Degree: \t " <<
        population[0].optimiserMutation << "\n" <<
        "And # Iterations: \t " <<
        numberOfIterations << "\n";
}

