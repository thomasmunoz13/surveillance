/**
 * @author Thomas Munoz
 */

#ifndef SURVEILLANCE_MAILSENDER_H
#define SURVEILLANCE_MAILSENDER_H

#include <string>

class MailSender {
private :
    const char * CLIENT = "HCSurveillance v1.0";

    std::string smtp;
    std::string login;
    std::string password;
    std::string senderName;
    std::string senderMail;
    int port;

public :

    MailSender(const std::string &smtp, const std::string &login, const std::string &password,
               const std::string &senderName, const std::string &senderMail, int port);

    bool send(const std::string destination, const std::string subject, const std::string message,
              const std::string attachment = "");
};


#endif //SURVEILLANCE_MAILSENDER_H
