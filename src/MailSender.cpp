/**
 * @author Thomas Munoz
 */

#include <iostream>
#include <fstream>
#include <sstream>
#include "MailSender.h"

MailSender::MailSender(const std::string & smtp, const std::string & login,
                       const std::string & password, const std::string & senderName,
                       const std::string & senderMail, int port)
        : smtp(smtp), login(login), password(password),
          senderName(senderName), senderMail(senderMail),
          port(port)
{}

bool MailSender::send(const std::string destination, const std::string subject,
                      const std::string message, const std::string attachment) {
    bool success = true;
    try {
        mail.SetSMTPServer(smtp.c_str(), this->port);

        mail.SetLogin(login.c_str());
        mail.SetPassword(password.c_str());

        mail.SetSenderMail(senderMail.c_str());
        mail.SetSenderName(senderName.c_str());
        mail.SetReplyTo(senderMail.c_str());
        mail.AddRecipient(destination.c_str());

        mail.SetSubject(subject.c_str());
        mail.SetXPriority(XPRIORITY_NORMAL);
        mail.SetXMailer(CLIENT);

        mail.AddMsgLine("<html>");
        mail.AddMsgLine(message.c_str());

        if(attachment.size() != 0){
            mail.AddAttachment(attachment.c_str());
        }

        mail.Send();


    } catch(ECSmtp e) {
        std::cerr << "Error while sending mail : "
        << e.GetErrorText()
        << std::endl;

        success = false;
    }

    return success;
}
