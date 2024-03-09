/***********************************************************************
// OOP244 Workshop # 6
//
// File: EmailFile.cpp
// Version 1.0
// Date:
// Author: Sina Talebi Moghaddam
// Description
// This file must be completed by students
// Revision History
// -----------------------------------------------------------
// Name            Date            Reason
//
/////////////////////////////////////////////////////////////////
***********************************************************************/
// Name: Thanatorn Wongthanaporn
// Email: twongthanaporn@myseneca.ca 
// id: 161197223
// Date: 8/3/2024

// I have done all the coding by myself and only copied the code that my
// professor provided to complete my workshops and assignments.
#define _CRT_SECURE_NO_WARNINGS

#include <fstream>
#include <cstring>
#include "EmailFile.h"

using namespace std;
namespace seneca
{

    Email& Email::operator=(const Email& rhs) {

        if (this != &rhs && rhs.m_email && rhs.m_name) {
            delete[] m_email;
            m_email = nullptr;
            m_email = new char[strlen(rhs.m_email) + 1];
            strcpy(m_email, rhs.m_email);
            delete[] m_name;
            m_name = nullptr;
            m_name = new char[strlen(rhs.m_name) + 1];
            strcpy(m_name, rhs.m_name);
            strcpy(m_year, rhs.m_year);
        }

        return *this;
    }

    bool Email::load(std::ifstream& in) {

        char buffer[BUFFER_SIZE];
        bool result = false;

        if (in.getline(buffer, BUFFER_SIZE, ',')) {
            delete[] m_email;
            m_email = new char[strlen(buffer) + 1];
            strcpy(m_email, buffer);

            if (in.getline(buffer, BUFFER_SIZE, ',')) {
                delete[] m_name;
                m_name = new char[strlen(buffer) + 1];
                strcpy(m_name, buffer);

                if (in.getline(buffer, BUFFER_SIZE, '\n')) {
                    strcpy(m_year, buffer);
                    result = true;
                }
            }
        }

        return result;
    }

   Email::~Email() {
      delete[] m_name;
      delete[] m_email;
   }

    void EmailFile::setFilename(const char* filename)
    {
        delete[] m_filename;
        m_filename = nullptr;
        if (filename)
        {
            m_filename = new char[strlen(filename) + 1];
            m_filename[0] = '\0';
            strcpy(m_filename, filename);
        }
    }

    void EmailFile::setEmpty()
    {
        delete[] m_emailLines;
        delete[] m_filename;
        m_emailLines = nullptr;
        m_filename = nullptr;
        m_noOfEmails = 0;
    }

    bool EmailFile::setNoOfEmails() {

        bool isValid = false;
        ifstream file(m_filename);

        if (!file.is_open()) {
            cout << "Failed to open file: " << m_filename << endl;
        }
        else
        {
            m_noOfEmails = 0;
            while (file) {
                m_noOfEmails += (file.get() == '\n');
            }
            file.close();

            if (m_noOfEmails == 0)
            {
                delete[] m_filename;
                m_filename = nullptr;
            }
            else {
                m_noOfEmails++;
                isValid = true;
            }
        }
        return isValid;
    }

    std::ostream& EmailFile::view(std::ostream& ostr) const
    {
        if (m_filename) {
            ostr << m_filename << endl;
            ostr.width(strlen(m_filename));
            ostr.fill('=');
            ostr << "=" << endl;
            ostr.fill(' ');
            for (int i = 0; i < m_noOfEmails; i++) {
                ostr.width(35);
                ostr.setf(ios::left);
                ostr << m_emailLines[i].m_email;
                ostr.width(25);
                ostr << m_emailLines[i].m_name;
                ostr << "Year = " << m_emailLines[i].m_year << endl;
            }
        }

            return ostr;
    }

    void EmailFile::loadEmails() {
        ifstream file(m_filename);
        int i=0;
        if (file) {
            delete[] m_emailLines;
            m_emailLines = new Email[m_noOfEmails];
            for (i = 0; i < m_noOfEmails && !file.eof(); i++) {
                if (!m_emailLines[i].load(file)) {
                    i--;
                    break;
                }
            }
            m_noOfEmails = i + 1;
        }
        file.close();
    }

    EmailFile::operator bool() const {
        return m_emailLines == nullptr && m_noOfEmails == 0 && m_filename == nullptr;
    }

    EmailFile::EmailFile() {
        m_filename = nullptr;
        m_noOfEmails = 0;
        m_emailLines = nullptr;
    }

    EmailFile::EmailFile(const char* filename) {
        if (filename) {
            setFilename(filename);
            setNoOfEmails();
            loadEmails();
        }
        else {
            m_noOfEmails = 0;
            m_emailLines = nullptr;
            m_filename = nullptr;
        }
    }

    EmailFile::EmailFile(const EmailFile& source) {
        m_filename = nullptr;
        m_emailLines = nullptr;
        (*this) = source;
    }

    EmailFile::~EmailFile() {
        delete[] m_filename;
        delete[] m_emailLines;
    }

    EmailFile& EmailFile::operator=(const EmailFile& source) {
        delete[] m_filename;
        delete[] m_emailLines;
        if (source.m_filename) {
            setFilename(source.m_filename);
            m_noOfEmails = source.m_noOfEmails;
            m_emailLines = new Email[m_noOfEmails];
            for (int i = 0; i < m_noOfEmails; i++) {
                m_emailLines[i] = source.m_emailLines[i];
            }
        }
        else {
            m_noOfEmails = 0;
            m_emailLines = nullptr;
            m_filename = nullptr;
        }
        return *this;
    }

    bool EmailFile::saveToFile(const char* filename) const {
        bool result;
        ofstream file(filename);
        if (result = file.is_open()) {
            for (int i = 0; i < m_noOfEmails; i++) {
                file << m_emailLines[i].m_email << "," << m_emailLines[i].m_name << "," << m_emailLines[i].m_year << endl;
            }
        }
        else {
            cout << "Error: Could not open file: " << filename << endl;
            result = 0;
        }
        file.close();
        return result;
    }
    void EmailFile::fileCat(const EmailFile& obj, const char* name) {
        int newNoOfEmails = 0;
        Email* newEmailLines = nullptr;
        if (this->valid() && obj.valid()) {
            newNoOfEmails = this->m_noOfEmails + obj.m_noOfEmails;
            newEmailLines = new Email[newNoOfEmails];
            for (int i = 0; i < this->m_noOfEmails; i++) {
                newEmailLines[i] = this->m_emailLines[i];
            }
            for (int i = 0; i < obj.m_noOfEmails; i++) {
                newEmailLines[i + this->m_noOfEmails] = obj.m_emailLines[i];
            }
            this->m_noOfEmails = newNoOfEmails;
            delete[] this->m_emailLines;
            this->m_emailLines = newEmailLines;
            if (name) {
                this->setFilename(name);
            }
            this->saveToFile(this->m_filename);
        }
    }

    bool EmailFile::valid() const {
        return !(m_filename == nullptr || m_emailLines == nullptr || m_noOfEmails == 0);
    }

    std::ostream& operator<<(std::ostream& ostr, const EmailFile& text)
    {
        return text.view(ostr);
    }

    
}