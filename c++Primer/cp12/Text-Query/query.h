class QueryResult;

using line_no = std::vector<std::string>::size_type;

class TextQuery{
public:
    TextQuery(std::ifstream &);
    QueryResult query(const std::string&) const;
private:
    std::shared_ptr<std::vector<std::string>> file;
    std::map<std::string, 
             std::shared_ptr<std::set<line_no>>> matches;
};

class QueryResult{
friend std::ostream& print (std::ostream&, const  QueryResult&);
public:
    QueryResult(std::string s,
                std::shared_ptr<std::set<line_no>> p,
                std::shared_ptr<std::vector<std::string>> f):
        sought(s), lines(p), file(f) {}
private:
    std::string sought;
    std::shared_ptr<std::set<line_no>> lines;
    std::shared_ptr<std::vector<std::string>> file;
}
;
TextQuery::TextQuery(std::ifstream &fin) : file(new std::vector<std::string>)
{
    std::string text;
    line_no n = 1;
    while (getline(fin, text))
    {
        file->push_back(text);
        std::istringstream iss(text);
        std::string word;

        while (iss >> word)
        {
            auto &lines = matches[word];
            if (!lines)
                lines.reset(new std::set<line_no>);
            lines->insert(n);
        }

        ++n;
    }
}

QueryResult TextQuery::query(const std::string &sought) const {
    static std::shared_ptr<std::set<line_no>> nodata (new std::set<line_no>);
    auto loc = matches.find(sought);
    if (loc == matches.end())
        return QueryResult (sought, nodata, file);
    else
        return QueryResult (sought, loc->second, file);
}

std::ostream& print(std::ostream &os, const QueryResult &qr)
{
    os << qr.sought << " occurs " << qr.lines->size() << " times" << std::endl;
    for (auto num : *qr.lines){
        os << "\t(line " << num << ") "
           << *(qr.file->begin() + (num - 1)) << std::endl;
    }
    return os;
}
