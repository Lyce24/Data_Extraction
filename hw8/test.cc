#include "huffman.hh"
#include <iostream>
#include <vector>

using namespace std;

int main()
{
    Huffman huff;

    // std::vector<int> test;
    // test.push_back(1);
    // test.push_back(1);
    // test.push_back(2);
    // test.push_back(1);
    // test.push_back(0);
    // test.push_back(1);
    // test.push_back(1);
    // test.push_back(2);
    // test.push_back(1);
    // test.push_back(0);
    // for (int i = 0; i < test.size(); i++)
    // {
    //     cout << "when input is: " << test[i] << endl;
    //     auto path = h.encode(test[i]);
    //     cout << path.size() << endl;
    //     cout << CHAR_BIT << endl;
    //     for (int i = 0; i < path.size(); i++)
    //     {
    //         cout << path[i];
    //     }
    //     cout << " " << endl;
    // }

    // auto path = h.encode(97);
    // cout << 97 << ":" ;
    // for (int i = 0; i < path.size(); i++)
    // {
    //     cout << path[i];
    // }
    // cout << " " << endl;
    // cout << path.size() << endl;
    // cout << CHAR_BIT << endl;

    auto bits = huff.encode('a');
    for (auto it = begin(bits); it != end(bits); ++it) {
    cout << *it;
    }
    cout << endl;

    bits = huff.encode('b');
    for (auto it = begin(bits); it != end(bits); ++it) {
    cout << *it;
    }
    cout << endl;

    bits = huff.encode('s');
    for (auto it = begin(bits); it != end(bits); ++it) {
    cout << *it;
    }
    cout << endl;

    bits = huff.encode('d');
    for (auto it = begin(bits); it != end(bits); ++it) {
    cout << *it;
    }
    cout << endl;

    bits = huff.encode(256);
    for (auto it = begin(bits); it != end(bits); ++it) {
    cout << *it;
    }
    cout << endl;
    // bits = huff.encode('a');
    // (bits.size() < CHAR_BIT);

    // bits = huff.encode('b');
    // (bits.size() < CHAR_BIT);

    // bits = huff.encode('b');
    // (bits.size() == huff.encode('a').size());

    // bits = huff.encode('b');
    // bits = huff.encode('b');
    // bits = huff.encode('b');
    // (bits.size() < huff.encode('a').size());

    // Huffman huff;
    // cout << "first a:" << endl;
    // auto bits = huff.encode('a');
    // cout << bits.size() << endl;
    // for (int i = 0; i < bits.size(); i++)
    // {
    //     cout << bits[i];
    // }
    // cout << " " << endl;

    // cout << "first b:" << endl;
    // bits = huff.encode('b');
    // cout << bits.size() << endl;
    // for (int i = 0; i < bits.size(); i++)
    // {
    //     cout << bits[i];
    // }
    // cout << " " << endl;

    // cout << "second a:" << endl;
    // bits = huff.encode('a');
    // cout << bits.size() << endl;
    // for (int i = 0; i < bits.size(); i++)
    // {
    //     cout << bits[i];
    // }
    // cout << " " << endl;

    // cout << "second b:" << endl;
    // bits = huff.encode('b');
    // cout << bits.size() << endl;
    // for (int i = 0; i < bits.size(); i++)
    // {
    //     cout << bits[i];
    // }
    // cout << " " << endl;

    // cout << "more bs:" << endl;
    // bits = huff.encode('b');
    // cout << bits.size() << endl;
    // for (int i = 0; i < bits.size(); i++)
    // {
    //     cout << bits[i];
    // }
    // cout << " " << endl;

    // bits = huff.encode('b');
    // bits = huff.encode('b');
    // bits = huff.encode('b');
    // cout << bits.size() << endl;
    // for (int i = 0; i < bits.size(); i++)
    // {
    //     cout << bits[i];
    // }
    // cout << " " << endl;

    // auto result = huff.decode(1);
    // cout << result << endl;
    // return 0;
}