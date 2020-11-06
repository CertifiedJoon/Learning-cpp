void print (const pair<string,vector<string>> &names){
    cout << names.first << " : ";
    ostream_iterator<string> out_it(cout, " ");
    copy((names.second).begin(), (names.second).end(), out_it);
    cout << endl;
}