/*
������� 2. �������� ������������ email-������
��� ����� �������
�������� ���������, ������� ��������� ������������ email-������, ��������� �������������.
�������� ������������� �����������, ���������� email-����� ������ �������� �� ���� ������, ���������� ������ @. 
������ ����� ������ ����� ����� �� ����� ������ � �� ����� 64 ��������, ������ ����� � �� ����� ������ � �� ����� 63 ��������. 
�� �������� ����������� ������ ���������� �����, ����� � ���� �-� (�����), � ����� �����. ����� �� ����� ���� ������ ��� ��������� ��������, 
� ����� ����, ��� ����� �� ����� ���� ������. � ������ ����� (������� ������������ ������� @), ����� �����������������, 
��������� ��� ��������� �������:
!#$%&'*+-/=?^_{|}~`
������������ ������ ������, �������� email-�����. ��������� ������ ������� ����� Yes, ���� ����� ���������, 
� � ��������� ������ � ����� No.
*/

#include <iostream>
#include <string>

using namespace std;

string get_first_part(string email){
    string answer = "";
    for (size_t i=0; i<email.size(); ++i){
        if (email[i] == '@'){
            return answer;
        }
        else {
            answer+=email[i];
        }
        if (i == email.size()-1){
            answer = "";
        }
    }
    return answer;
}

string get_second_part(string email){
    string answer = "";
    bool meet_symbol = false;
    for (size_t i=0; i< email.size(); ++i){
        if (meet_symbol){
            answer+=email[i];
        }
        else if (email[i] == '@'){
            meet_symbol = true;
        }
    }
    return answer;
}

bool correct_email(string email){
    string correct_symbol = {'A' , 'B' , 'C' , 'D' , 'E' , 'F' , 'G' , 'H' , 'I' , 'J' , 'K' , 'L' , 'M' , 'N' , 'O' , 'P' , 
                                'Q' , 'R' , 'S' , 'T' , 'U' , 'V' , 'W' , 'X' , 'Y' , 'Z',
                                'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 
                                't', 'u', 'v', 'w', 'x', 'y', 'z',
                                '0','1','2','3','4','5','6','7','8','9',
                                '-','.'};

    string first_part_correct_symbol = {'!','#','$','%','&','\'','*','+','-','/','=','?','^','_','{','|','}','~','`'};

    string first_part = get_first_part(email);
    string second_part = get_second_part(email);

    if (first_part.size() < 1 || first_part.size() > 64 || second_part.size() < 1 || second_part.size() > 63){
        return false;
    }

    if (first_part.front() == '.' || second_part.back() == '.'){
        return false;
    }
    
    for (size_t i=0; i<first_part.size(); ++i){
        if (first_part[i] == '.' && i+1<first_part.size() && first_part[i+1] == '.'){
            return false;
        }

        if (correct_symbol.find(first_part[i]) == string::npos &&
            first_part_correct_symbol.find(first_part[i]) == string::npos){
                return false;
        }
    }

    for (size_t i=0; i<second_part.size(); ++i){
        if (second_part[i] == '.' && i+1<second_part.size() && second_part[i+1] == '.'){
            return false;
        }

        if (correct_symbol.find(second_part[i]) == string::npos){
                return false;
        }        
    }

    return true;
}

int main(){
    setlocale(LC_ALL, "Russian");
    string email;
    cout << "������� email-�����: ";
    cin >> email;

    if (correct_email(email)){
        cout << "Yes";
    }
    else {
        cout << "No";
    }
}