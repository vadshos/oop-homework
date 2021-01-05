#include "Quest.h"

const std::string& Quest::getQuestion() const
{
    return question;
}

const std::string& Quest::getAnswer() const
{
    return answer;
}

Quest::Quest(const std::string question, const std::string answer)
{
    if(!question.empty())
        if (!answer.empty())
        {
            this->question = question;
            this->answer = answer;
        }

}
