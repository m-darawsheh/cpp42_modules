#include "PmergeMe.hpp"
#include <cctype>
#include <algorithm>
#include <sys/time.h>
#include <iomanip>

PmergeMe::PmergeMe()
{

}


PmergeMe::~PmergeMe()
{
    
}


PmergeMe::PmergeMe(const PmergeMe &obj)
{
    (void)obj;
}


PmergeMe  &PmergeMe::operator=(const PmergeMe &obj)
{
    (void)obj;
    return *this;
}

bool isnum(std::string token)
{
    size_t i = 0;
    while (i < token.size())
    {
    if (!std::isdigit(static_cast<unsigned char>(token[i])))
        {
            return false ;
        }
        i++;
    }
    return true;
}

void PmergeMe::validation(std::string arg)
{
   std::istringstream istream(arg);
   std::string token;
   while(getline(istream,token,' '))
   {
        if (token.empty())
            continue; // skip extra spaces
        if (token[0] == '-' || !isnum(token))
        {
            std::cerr<<"Error" << std::endl;
            exit(1);
            return ;
        }
   }
}


static size_t count_vector = 0;


static std::vector<size_t> get_jacaob_sec(size_t n)
{
    std::vector<size_t> order;
    order.reserve(n);
    if (n == 0)
        return order;

    std::vector<size_t> jac;
    size_t j1 = 1;
    size_t j2 = 1;
    while (j1 <= n)
    {
        jac.push_back(j1);
        size_t j_next = 2 * j2 + j1;
        j2 = j1;
        j1 = j_next;
    }

    std::vector<char> used(n, 0);
    for (size_t k = 0; k < jac.size(); ++k)
    {
        size_t j = jac[k];
        if (j == 0) continue;
        size_t idx = j - 1;
        if (idx < n && !used[idx])
        {
            order.push_back(idx);
            used[idx] = 1;
        }
    }
    for (size_t i = 0; i < n; ++i)
    {
        if (!used[i])
        {
            order.push_back(i);
            used[i] = 1;
        }
    }
    return order;

}

std::deque<int> rece_deque(std::deque<int> &data)
{
    std::deque<int> main_chain;
    std::deque<int> pend;
    std::deque<int> new_main;
    std::deque<int> result;
    bool isodd;

    if (data.empty())
        return std::deque<int>();
    if (data.size() == 1)
        return data;
    if (data.size() == 2)
    {
        result = data;
        count_vector++;
        if (result[0] > result[1])
            std::swap(result[0], result[1]);
        return result;
    }
    isodd = (data.size() % 2 == 1);
    std::deque<int>::iterator it = data.begin();
    while (it != data.end())
    {
        if ((it + 1) == data.end())
            break;
        count_vector++;
        if (*it > *(it + 1))
        {
            main_chain.push_back(*it);
            pend.push_back(*(it + 1));
        }
        else
        {
            pend.push_back(*it);
            main_chain.push_back(*(it + 1));
        }
        it += 2;
    }
    if (isodd)
        pend.push_back(data.back());
    new_main = rece_deque(main_chain);
    result = new_main;
    std::vector<size_t> order = get_jacaob_sec(pend.size());
    for (size_t t = 0; t < order.size(); ++t)
    {
        int val = pend[order[t]];
        std::deque<int>::iterator pos = std::lower_bound(result.begin(), result.end(), val);
        result.insert(pos, val);
    }
    return result;
}


std::vector<int> rece_vector(std::vector<int> &data)
{
    std::vector<int> main_chain;
    std::vector<int> pend;
    std::vector<int> new_main;
    std::vector<int> result;
    bool isodd;
    
    if (data.empty())
        return std::vector<int>();
    if (data.size() == 1)
        return data;
    if (data.size() == 2)
    {
        result = data;
        count_vector++;
        if (result[0] > result[1])
            std::swap(result[0], result[1]);
        return result;
    }
    
    isodd = (data.size() % 2 == 1);
    std::vector<int>::iterator it = data.begin();
    while (it != data.end())
    {
        if ((it + 1) == data.end())
            break;
        count_vector++;
        if (*it > *(it + 1))
        {
            main_chain.push_back(*it);
            pend.push_back(*(it + 1));
        }
        else
        {
            pend.push_back(*it);
            main_chain.push_back(*(it + 1));
        }
        it += 2;
    }
    
    if (isodd)
        pend.push_back(data.back());
    
    new_main = rece_vector(main_chain);

    result = new_main;
    std::vector<size_t> order = get_jacaob_sec(pend.size());
    for (size_t t = 0; t < order.size(); ++t)
    {
        int val = pend[order[t]];
        std::vector<int>::iterator pos = std::lower_bound(result.begin(), result.end(), val);
        result.insert(pos, val);
    }
    
    return result;
}

void sort_vec(std::string arg)
{
    std::vector<int> v_tem;
    std::deque<int> q_tem;
    std::istringstream istream(arg);
    std::string token;
    
    while (getline(istream, token, ' '))
    {
        if (token.empty())
            continue;
        v_tem.push_back(std::atoi(token.c_str()));
        q_tem.push_back(std::atoi(token.c_str()));
    }
    
    std::cout << "Before: ";
    for (size_t i = 0; i < v_tem.size(); i++)
    {
        std::cout << v_tem[i];
        if (i + 1 < v_tem.size())
            std::cout << " ";
    }
    std::cout << std::endl;
    
    count_vector = 0;
    timeval start, end;
    gettimeofday(&start, NULL);
    std::vector<int> sorted = rece_vector(v_tem);
    gettimeofday(&end, NULL);
    double elapsed = (end.tv_sec - start.tv_sec) * 1e6 + (end.tv_usec - start.tv_usec);

    std::cout << "After: ";
    for (size_t i = 0; i < sorted.size(); i++)
    {
        std::cout << sorted[i];
        if (i + 1 < sorted.size())
            std::cout << " ";
    }

    timeval start_deque, end_deque;
    gettimeofday(&start_deque, NULL);
    std::deque<int> sorted_deque = rece_deque(q_tem);
    gettimeofday(&end_deque, NULL);
    double elapsed_deque = (end_deque.tv_sec - start_deque.tv_sec) * 1e6 + (end_deque.tv_usec - start_deque.tv_usec);

    std::cout << std::endl;
    std::cout << "Time to process a range of " << v_tem.size() << " elements with std::vector : ";
    std::cout << std::fixed << std::setprecision(5) << elapsed << " us" << std::endl;
    std::cout << "Time to process a range of " << q_tem.size() << " elements with std::deque : ";
    std::cout << std::fixed << std::setprecision(5) << elapsed_deque << " us" << std::endl;
}

PmergeMe::PmergeMe(char *arg[])
{
    int i = 1;
    while (arg[i])
    {
        std::string arg_str = arg[i];
        validation(arg_str);
        i++;
    }
    std::string combined_args;
    i = 1;
    while (arg[i])
    {
        combined_args += arg[i];
        combined_args += " ";
        i++;
    }
    sort_vec(combined_args);
}