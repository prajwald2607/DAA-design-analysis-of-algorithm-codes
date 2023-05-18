#include <iostream>
#include <unordered_map>
#include <queue>
#include <string>
using namespace std;
struct Node
{
    char data;
    int freq;
    Node *left;
    Node *right;
    Node(char data, int freq)
    {
        this->data = data;
        this->freq = freq;
        this->left = this->right = nullptr;
    }
    ~Node()
    {
        delete left;
        delete right;
    }
};
struct comparator
{
    bool operator()(Node *l, Node *r)
    {
        return l->freq > r->freq;
    }
};
void encode(Node *root, string str, unordered_map<char, string> &huffmancode)
{
    if (!root)
    {
        return;
    }
    if (!root->left && !root->right)
    {
        huffmancode[root->data] = str;
    }
    encode(root->left, str + "0", huffmancode);
    encode(root->right, str + "1", huffmancode);
}
void decode(Node *root, int &index, string str)
{
    if (!root)
    {
        return;
    }
    if (!root->left && !root->right)
    {
        cout << root->data;
        return;
    }
    index++;
    if (str[index] == '0')
    {
        decode(root->left, index, str);
    }
    else
    {
        // str[index]=='1';
        decode(root->right, index, str);
    }
}

void huffmancoding(string text, unordered_map<char, int> freq)
{
    priority_queue<Node *, vector<Node *>, comparator> pq;
    for (auto pair : freq)
    {
        pq.push(new Node(pair.first, pair.second));
    }

    while (pq.size() != 1)
    {
        Node *left = pq.top();
        pq.pop();
        Node *right = pq.top();
        pq.pop();
        Node *parent = new Node('$', left->freq + right->freq);
        parent->left = left;
        parent->right = right;
        pq.push(parent);
    }
    Node *root = pq.top();
    unordered_map<char, string> huffmancode;
    encode(root, "", huffmancode);
    cout << "Huffman Codes for each Character are: " << endl;
    for (auto pair : huffmancode)
    {
        cout << pair.first << ":" << pair.second << endl;
    }
    cout << "Original text: " << text << endl;
    string encodedtext = "";
    for (char c : text)
    {
        encodedtext += huffmancode[c];
    }
    cout << "Encoded text is: " << encodedtext << endl;

    int index = -1;
    cout << "Decoded Text is: " << endl;
    while (index < (int)encodedtext.size() - 2)
    {
        decode(root, index, encodedtext);
    }
    cout << endl;
    delete root;
}
int main()
{
    string text;
    unordered_map<char, int> freq;

    cout << "Enter the text string to be encoded: " << endl;
    getline(cin, text);

    for (char c : text)
    {
        if (freq.find(c) != freq.end())
        {
            freq[c]++;
        }
        else
        {
            int f;
            cout << "Enter the frequency of the " << c << ": ";
            cin >> f;
            freq[c] = f;
        }
    }
    huffmancoding(text, freq);
    return 0;
}
/*
Output:
Enter the text string to be encoded:
abcdef
Enter the frequency of the a: 5
Enter the frequency of the b: 9
Enter the frequency of the c: 12
Enter the frequency of the d: 13
Enter the frequency of the e: 16
Enter the frequency of the f: 45
Huffman Codes for each Character are:
e:111
c:100
f:0
a:1100
d:101
b:1101
Original text: abcdef
Encoded text is: 110011011001011110
Decoded Text is:
abcde
*/