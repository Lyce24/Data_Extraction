#include "cities.hh"
#include <math.h>
#include <fstream>
#include <random>
#include <time.h>

// using namespace std;

// double total_path_distance(const std::vector<int> &ordering, std::vector<std::pair<int, int>> cities)
// {
//     double distance = 0.0;
//     std::pair<int, int> beginning;
//     std::pair<int, int> temp;
//     int index = 0;
//     for (const auto &i : ordering)
//     {
//         cout << "index: " << i << endl;
//         cout << "number in permutation: " << i << endl;
//         if (index == 0)
//         {
//             cout << "temp before: " << temp.first << ", ";
//             cout << temp.second << endl;
//             temp.first = cities[i].first;
//             temp.second = cities[i].second;
//             beginning.first = cities[i].first;
//             beginning.second = cities[i].second;
//             cout << "temp after: " << temp.first << ", ";
//             cout << temp.second << endl;
//             cout << distance << endl;
//             index++;
//         }
//         else
//         {
//             cout << "temp before: " << temp.first << ", ";
//             cout << temp.second << endl;
//             distance += sqrt(pow(cities[i].first - temp.first, 2) + pow(cities[i].second - temp.second, 2));
//             temp.first = cities[i].first;
//             temp.second = cities[i].second;
//             cout << "temp after: " << temp.first << ", ";
//             cout << temp.second << endl;
//             cout << distance << endl;
//         }
//     }
//     distance += sqrt(pow(beginning.first - temp.first, 2) + pow(beginning.second - temp.second, 2));
//     return distance;
// }

// // std::istream& operator>>(std::istream& is, Cities& cities)
// // {

// // }

// std::vector<int> random_permutation(unsigned len)
// {
//     vector<int> temp, result;

//     // Fill the vector with the values
//     // 1, 2, 3, ..., n
//     for (int i = 0; i < len; i++)
//         temp.push_back(i);

//     // While vector has elements
//     // get a random number from the vector and print it
//     while (temp.size())
//     {
//         int n = temp.size();

//         int index = rand() % n;
//         int num = temp[index];
//         cout << num << endl;

//         swap(temp[index], temp[n - 1]);
//         temp.pop_back();
//         result.push_back(num);
//     }

//     for (int i = 1; i <= 10; i++)
//     {
//         int index = rand();
//         cout << index << endl;
//     }

//     return result;
// }

int main()
{
    // srand(time(NULL));
    // std::vector<int> result = random_permutation(5);
    // cout << "Output of begin and end: ";
    // for (auto i = result.begin(); i != result.end(); ++i)
    //     cout << *i << " ";
    // result = random_permutation(5);
    // cout << "Output of begin and end: ";
    // for (auto i = result.begin(); i != result.end(); ++i)
    //     cout << *i << " ";
    // result = random_permutation(5);
    // cout << "Output of begin and end: ";
    // for (auto i = result.begin(); i != result.end(); ++i)
    //     cout << *i << " ";
    // result = random_permutation(5);
    // cout << "Output of begin and end: ";
    // for (auto i = result.begin(); i != result.end(); ++i)
    //     cout << *i << " ";
    // return 0;

    //     10  5
    // 2 20
    // 15  12
    // 15  7
    // 7 7
    // const std::vector<int> test = {0,1,2,3,4};
    // std::vector<std::pair<int,int>> cities = {{10,5},{2,20},{15,12},{15,7},{7,7}};
    // double result = total_path_distance(test,cities);
    // cout << "distance: " << result << endl;
    // return 0;

    // string filename("five.txt");
    // int number;

    // ifstream input_file(filename);
    // if (!input_file.is_open()) {
    //     cerr << "Could not open the file - '"
    //          << filename << "'" << endl;
    //     return EXIT_FAILURE;
    // }

    // while (input_file >> number) {
    //     cout << number << "; ";
    // }
    // cout << endl;
    // input_file.close();

    // return EXIT_SUCCESS;
    auto fin = std::ifstream("five.tsv");
    Cities cities;
    fin >> cities;

    const char *more = "shortest.tsv";
    std::ofstream outfile(more);

    double shortest;
    shortest = cities.total_path_distance(cities.random_p);
    cout << 1 << "\t";
    cout << shortest << endl;
    for (int i = 0; i < 120; i++)
    {
        std::vector<unsigned> random_per = cities.random_permutation(cities.random_p.size());


        // for (auto i = random_per.begin(); i != random_per.end(); ++i)
        // {
        //     cout << *i << " ";
        // }
        // cout << endl;

        // if (i == 0)
        // {
        //     shortest = cities.total_path_distance(random_p);
        // }
        // else
        // {
        //     double temp = cities.total_path_distance(random_p);
        //     if (temp < shortest)
        //     {
        //         // cities = cities.reorder(random_p);
        //         shortest = temp;
        //         cout << i << "\t";
        //         cout << shortest << endl;
        //     }
        //     else
        //     {
        //         continue;
        //     }
        // }
      
        double temp = cities.total_path_distance(random_per);
        if (temp < shortest)
        {
            cities = cities.reorder(random_per);
            // cities = cities.reorder(random_p);
            shortest = temp;
            cout << i + 2 << "\t";
            cout << shortest << endl;
        }
        else
        {
            continue;
        }
        outfile << cities;
    }

    fin.close();
    outfile.close();
    

    return 0;
}