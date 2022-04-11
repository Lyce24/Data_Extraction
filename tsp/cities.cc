#include "cities.hh"

using namespace std;
default_random_engine generator;

using namespace std;

Cities::Cities(Cities::permutation_t p)
    :random_p(p)
{
}


double Cities::total_path_distance(const permutation_t &ordering) const
{
    double distance = 0.0;
    Cities::coord_t beginning;
    Cities::coord_t temp;
    int index = 0;
    for (const auto &i : ordering)
    {
        if (index == 0)
        {
            temp.first = cities[i].first;
            temp.second = cities[i].second;
            beginning.first = cities[i].first;
            beginning.second = cities[i].second;
            index++;
        }
        else
        {
            distance += sqrt(pow(cities[i].first - temp.first, 2) + pow(cities[i].second - temp.second, 2));
            temp.first = cities[i].first;
            temp.second = cities[i].second;
        }
    }
    distance += sqrt(pow(beginning.first - temp.first, 2) + pow(beginning.second - temp.second, 2));
    return distance;
}

// Cities reorder(const Cities::permutation_t &ordering) const
// {

// }

std::istream &operator>>(std::istream &is, Cities &C)
{
    int number;
    int index = 0;
    while (is >> number)
    {
        if (index == 0)
        {
            C.temp.first = number;
            index++;
        }
        else
        {
            C.temp.second = number;
            C.cities.push_back(C.temp);
            index = 0;
        }
    }

    for (auto i = C.cities.begin(); i != C.cities.end(); ++i)
    {
        C.random_p.push_back(index);
        index++;
    }

    return is;
}

std::ostream &operator<<(std::ostream &os, Cities &C)
{    
    for (auto i = C.random_p.begin(); i != C.random_p.end(); ++i)
    {
        os << C.cities[*i].first;
        os << "\t";
        os << C.cities[*i].second;
        os << "\n";
    }
    return os;
}

Cities::permutation_t Cities::random_permutation(unsigned len)
{
    permutation_t result;
    // int ind = 0;
    // Fill the vector with the values
    // 0, 1, 2, ..., len
    // for (int i=0; i<random_p.size(); i++)
    //     temp.push_back(random_p[i]);
    // while (temp.size() != len)
    // {
    //     uniform_int_distribution<int> distribution(0, len - 1);
    //     int i = distribution(generator);
    //     if (ind != 0)    
    //     { 
    //         if (std::count(temp.begin(), temp.end(), i))
    //         {
    //             continue;
    //         }
    //         else
    //         {
    //             temp.push_back(i);
    //         }
    //     }  
    //     else
    //     {
    //         temp.push_back(i);
    //         ind++;
    //     }
    // }

    // While vector has elements
    // get a random number from the vector and print it
    while (random_p.size())
    {
        int n = random_p.size();
        uniform_int_distribution<int> distribution(0, n - 1);
        int index = distribution(generator);
        int num = random_p[index];

        result.push_back(num);
        swap(random_p[index], random_p[n - 1]);
        random_p.pop_back();
    }

    random_p = result;
    return random_p;
}

Cities Cities::reorder(const Cities::permutation_t &ordering) const
{
    Cities c(ordering);
    return c;
}