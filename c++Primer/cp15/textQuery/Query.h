#ifndef QUERY_H
#define QUERY_H

#include "Query_base.h"
#include "textquery.h"
#include "WordQuery.h"

class Query{
    friend Query operator~(const Query &);
    friend Query operator|(const Query &, const Query &);
    friend Query operator&(const Query &, const Query &);
public:
    Query(const std::string&);
    QueryResult eval(const  TextQuery &t) const 
                            { return q->eval(t); }
    std::string rep() const { return q->rep(); }

private:
    Query(std::shared_ptr<Query_base> query): q(query) {}
    std::shared_ptr<Query_base> q;
};

std::ostream&
operator<<(std::ostream &os, const Query &query)
{
    return os << query.rep();
}

#endif