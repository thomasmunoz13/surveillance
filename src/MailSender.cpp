/**
 * @author Thomas Munoz
 */

#include <iostream>
#include "MailSender.h"
#include "../include/CSmtp.h"

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
    CSmtp mail;

    try {
        mail.SetSMTPServer(this->smtp.c_str(), this->port);

        mail.SetLogin(this->login.c_str());
        mail.SetPassword(this->password.c_str());

        mail.SetSenderMail(this->senderMail.c_str());
        mail.SetSenderName(this->senderName.c_str());
        mail.SetReplyTo(this->senderMail.c_str());
        mail.AddRecipient(destination.c_str());

        mail.SetSubject(subject.c_str());
        mail.SetXPriority(XPRIORITY_NORMAL);
        mail.SetXMailer(CLIENT);

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
