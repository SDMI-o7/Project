#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <chrono>
#include <ctime>

using namespace std;

class package
{

    friend string viewPkgStatus(vector<package> &);
    friend float compute_package(vector<package> &);
    friend bool insertPkg(vector<package> &);
    friend void savePkgFile(vector<package> &, fstream &);
    friend void readPkgFile(vector<package> &, fstream &);

protected:
    string id, reciever, sender;
    float weight;
    float weight_rate = 10000;
    string status = "Dar hale amade sazi";

public:
    package(string w = "", string x = "", string y = "", float z = 0)
    {
        id = w;
        reciever = x;
        sender = y, weight = z;
    }
    package(const package &x)
    {
        id = x.id;
        reciever = x.reciever;
        sender = x.sender, weight = x.weight;
    }
    float compute_price()
    {
        cout << "hazine post: ";
        return weight * weight_rate;
    }
    ~package() {}
};

float compute_package(vector<package> &pkg)
{
    string user_id;
    cin >> user_id;
    for (int i = 0; i < pkg.size(); i++)
    {
        if (user_id == pkg[i].id)
        {
            return (pkg[i].weight_rate * pkg[i].weight);
        }
        else
        {
            continue;
        }
    }
    return 0;
}

class pishtaz : public package
{
    friend string viewPishStatus(vector<pishtaz> &);
    friend float compute_pish(vector<pishtaz> &);
    friend bool insertPish(vector<pishtaz> &);
    friend void savePishFile(vector<pishtaz> &, fstream &);
    friend void readPishFile(vector<pishtaz> &, fstream &);

private:
    int pish_price = 30000;

public:
    // float compute_pish(){return pish_price + (weight_rate * weight);}
    ~pishtaz() {}
};

float compute_pish(vector<pishtaz> &pish)
{
    string user_id;
    cin >> user_id;
    for (int i = 0; i < pish.size(); i++)
    {
        if (user_id == pish[i].id)
        {
            return pish[i].pish_price + (pish[i].weight_rate * pish[i].weight);
        }
        else
        {
            continue;
        }
    }
    return 0;
}

class tipax : public package
{
    friend string viewPaxStatus(vector<tipax> &);
    friend float compute_tipax(vector<tipax> &);
    friend bool insertPax(vector<tipax> &);
    friend void savePaxFile(vector<tipax> &, fstream &);
    friend void readPaxFile(vector<tipax> &, fstream &);

private:
    int pax_price = 25000;

public:
    float compute_price()
    {
        cout << "hazine tipax: ";
        if (weight <= 6)
            return weight_rate * weight;
        else
        {
            weight_rate = 16000;
            return weight_rate * weight;
        }
    }

    ~tipax() {}
};
float compute_tipax(vector<tipax> &pax)
{
    string user_id;
    cin >> user_id;
    for (int i = 0; i < pax.size(); i++)
    {
        if (user_id == pax[i].id)
        {
            if (pax[i].weight <= 6)
                return pax[i].weight_rate * pax[i].weight;
            else
            {
                pax[i].weight_rate = 16000;
                return pax[i].weight_rate * pax[i].weight;
            }
        }
        else
            continue;
    }
    return 0;
}

class bar_bari : public package
{
    friend string viewBarStatus(vector<bar_bari> &);
    friend float compute_bar_bari(vector<bar_bari> &);
    friend bool insertBar(vector<bar_bari> &);
    friend void saveBarFile(vector<bar_bari> &, fstream &);
    friend void readBarFile(vector<bar_bari> &, fstream &);

private:
    int bar_price = 20000;

public:
    bar_bari() {}
    float compute_price()
    {
        cout << "hazine bar bari: ";
        if (weight >= 10)
            return bar_price + (weight_rate * weight);
        else
        {
            cout << "Baraye estefade az post bar bari marsoole shoma bayad bish az 10,000 gram vazn dashte bashad!\n";
            return 0;
        }
    }
    ~bar_bari() {}
};

float compute_bar_bari(vector<bar_bari> &bar)
{
    string user_id;
    cin >> user_id;
    for (int i = 0; i < bar.size(); i++)
    {
        if (user_id == bar[i].id)
        {
            return bar[i].bar_price + (bar[i].weight_rate * bar[i].weight);
        }
        else
            continue;
    }
    return 0;
}

class dakhel_shahri : public package
{
    friend string viewDakhelStatus(vector<dakhel_shahri> &);
    friend float compute_dakhel_shahri(vector<dakhel_shahri> &);
    friend bool insertDakhel(vector<dakhel_shahri> &);
    friend void saveDakhelFile(vector<dakhel_shahri> &, fstream &);
    friend void readDakhelFile(vector<dakhel_shahri> &, fstream &);

private:
    int dakhel_price = 10000;
    float over_weight;

public:
    dakhel_shahri() {}
    float compute_price()
    {
        cout << "hazine dakhel shahri: ";
        if (weight <= 5)
            return weight_rate * weight;
        else
        {
            over_weight = (weight - 5);
            return (dakhel_price * over_weight) + (weight_rate * weight);
        }
    }
    ~dakhel_shahri() {}
};

float compute_dakhel_shahri(vector<dakhel_shahri> &dakhel)
{
    string user_id;
    cin >> user_id;
    for (int i = 0; i < dakhel.size(); i++)
    {
        if (user_id == dakhel[i].id)
        {
            if (dakhel[i].weight <= 5)
                return dakhel[i].weight_rate * dakhel[i].weight;
            else

                float over_weight = (dakhel[i].weight - 5);
            return (dakhel[i].dakhel_price * dakhel[i].over_weight) + (dakhel[i].weight_rate * dakhel[i].weight);
        }
        else
            continue;
    }
    return 0;
}

bool insertPkg(vector<package> &pack)
{
    package p;
    cout << "post adii \n";
    cout << "vazn basteh ra vared konid: ";
    cin >> p.weight;
    cout << "Etelaat frestandeh ra vared konid: ";
    cin >> p.sender;
    cout << "Etelaat girandeh ra vared konid: ";
    cin >> p.reciever;
    pack.push_back(p);
    return true;
}

void readPkgFile(vector<package> &pack, fstream &outfile)
{
    package temp;
    outfile.open("packages_list.txt", ios::in);
    while (!outfile.eof())
    {
        outfile >> temp.id >> temp.sender >> temp.reciever >> temp.weight;
        pack.push_back(temp);
    }
    outfile.close();
}

void savePkgFile(vector<package> &x, fstream &outfile)
{
    outfile.open("packages_list.txt", ios::out);
    outfile << "post adii:\n";
    for (int i = 0; i < x.size(); i++)
    {
        outfile << "package num. " << i + 1 << ':' << endl;
        outfile << "id: " << x[i].id << endl;
        outfile << "sender id: " << x[i].sender << endl;
        outfile << "reciever id: " << x[i].reciever << endl;
    }
    outfile.close();
}

bool insertPish(vector<pishtaz> &pish)
{
    pishtaz s;
    cout << "post pishtaz \n";
    cout << "vazn basteh ra vared konid: ";
    cin >> s.weight;
    cout << "Etelaat frestandeh ra vared konid: ";
    cin >> s.sender;
    cout << "Etelaat girandeh ra vared konid: ";
    cin >> s.reciever;
    pish.push_back(s);
    return true;
}

void readPishFile(vector<pishtaz> &pish, fstream &outfile)
{
    pishtaz temp;
    outfile.open("packages_list.txt", ios::in);
    while (!outfile.eof())
    {
        outfile >> temp.id >> temp.sender >> temp.reciever >> temp.weight;
        pish.push_back(temp);
    }
    outfile.close();
}

void savePishFile(vector<pishtaz> &x, fstream &outfile)
{
    outfile.open("packages_list.txt", ios::out);
    outfile << "post pishtaz:\n";
    for (int i = 0; i < x.size(); i++)
    {
        outfile << "package num. " << i + 1 << endl;
        outfile << "id: " << x[i].id << " ";
        outfile << "sender id: " << x[i].sender;
        outfile << "reciever id: " << x[i].reciever << " ";
    }
    outfile.close();
}

bool insertPax(vector<tipax> &pax)
{
    tipax t;
    cout << "post tipax \n";
    cout << "vazn basteh ra vared konid: ";
    cin >> t.weight;
    cout << "Etelaat frestandeh ra vared konid: ";
    cin >> t.sender;
    cout << "Etelaat girandeh ra vared konid: ";
    cin >> t.reciever;
    pax.push_back(t);
    return true;
}

void readPaxFile(vector<tipax> &pax, fstream &outfile)
{
    tipax temp;
    outfile.open("packages_list.txt", ios::in);
    while (!outfile.eof())
    {
        outfile >> temp.id >> temp.sender >> temp.reciever >> temp.weight;
        pax.push_back(temp);
    }
    outfile.close();
}

void savePaxFile(vector<tipax> &x, fstream &outfile)
{
    outfile.open("packages_list.txt", ios::out);
    outfile << "post tipax :\n";
    for (int i = 0; i < x.size(); i++)
    {
        outfile << "package num. " << i + 1 << ':' << endl;
        outfile << "id: " << x[i].id << endl;
        outfile << "sender id: " << x[i].sender << endl;
        outfile << "reciever id: " << x[i].reciever << endl;
    }
    outfile << endl;
    outfile.close();
}

bool insertBar(vector<bar_bari> &bar)
{
    bar_bari b;
    float user_weight;
    cout << "post bar bari \n";

    cin >> user_weight;
    if (user_weight < 10)
    {
        return false;
    }
    else
    {
        b.weight = user_weight;
    }
    cout << "Etelaat frestandeh ra vared konid: ";
    cin >> b.sender;
    cout << "Etelaat girandeh ra vared konid: ";
    cin >> b.reciever;
    bar.push_back(b);
    return true;
}

void readBarFile(vector<bar_bari> &bar, fstream &outfile)
{
    bar_bari temp;
    outfile.open("packages_list.txt", ios::in);
    while (!outfile.eof())
    {
        outfile >> temp.id >> temp.sender >> temp.reciever >> temp.weight;
        bar.push_back(temp);
    }
    outfile.close();
}

void saveBarFile(vector<bar_bari> &x, fstream &outfile)
{
    outfile.open("packages_list.txt", ios::out);
    outfile << "post barbari:\n";
    for (int i = 0; i < x.size(); i++)
    {
        outfile << "package num. " << i + 1 << ':' << endl;
        outfile << "id: " << x[i].id << endl;
        outfile << "sender id: " << x[i].sender << endl;
        outfile << "reciever id: " << x[i].reciever << endl;
    }
    outfile << endl;
    outfile.close();
}

bool insertDakhel(vector<dakhel_shahri> &dakhel)
{
    dakhel_shahri d;
    cout << "post Dakhel shahri: \n";
    // سی اوت هایی که بفهمه کاربر چیه اینا باید چکار کنه
    cout << "vazn basteh ra vared konid: ";
    cin >> d.weight;
    cout << "Etelaat frestandeh ra vared konid: ";
    cin >> d.sender;
    cout << "Etelaat girandeh ra vared konid: ";
    cin >> d.reciever;
    dakhel.push_back(d);
    return true;
}

void readDakhelFile(vector<dakhel_shahri> &dakhel, fstream &outfile)
{
    dakhel_shahri temp;
    outfile.open("packages_list.txt", ios::in);
    while (!outfile.eof())
    {
        outfile >> temp.id >> temp.sender >> temp.reciever >> temp.weight;
        dakhel.push_back(temp);
    }
    outfile.close();
}

void saveDakhelFile(vector<dakhel_shahri> &x, fstream &outfile)
{
    outfile.open("packages_list.txt", ios::out);
    outfile << "post dakhel shari:\n";
    for (int i = 0; i < x.size(); i++)
    {
        outfile << "package num. " << i + 1 << ':' << endl;
        outfile << "id: " << x[i].id << endl;
        outfile << "sender id: " << x[i].sender << endl;
        outfile << "reciever id: " << x[i].reciever << endl;
    }
    outfile << endl;
    outfile.close();
}

string viewPkgStatus(vector<package> &x)
{
    string user_id;
    cout << "kod rahgiri baste khod ra vared konid" << endl;
    cin >> user_id;
    for (int i = 0; i < x.size(); i++)
    {
        if (user_id == x[i].id)
        {
            return x[i].status;
        }
        else
            continue;
    }
    cout << "basteh mor nazar pida nashod" << endl;
    return " ";
}

string viewPishStatus(vector<pishtaz> &x)
{
    string user_id;
    cout << "kod rahgiri baste khod ra vared konid" << endl;
    cin >> user_id;
    for (int i = 0; i < x.size(); i++)
    {
        if (user_id == x[i].id)
        {
            return x[i].status;
        }
        else
            continue;
    }
    cout << "basteh mor nazar pida nashod" << endl;
    return " ";
}

string viewPaxStatus(vector<tipax> &x)
{
    string user_id;
    cout << "kod rahgiri baste khod ra vared konid" << endl;
    cin >> user_id;
    for (int i = 0; i < x.size(); i++)
    {
        if (user_id == x[i].id)
        {
            return x[i].status;
        }
        else
            continue;
    }
    cout << "basteh mor nazar pida nashod" << endl;
    return " ";
}

string viewBarStatus(vector<bar_bari> &x)
{
    string user_id;
    cout << "kod rahgiri baste khod ra vared konid" << endl;
    cin >> user_id;
    for (int i = 0; i < x.size(); i++)
    {
        if (user_id == x[i].id)
        {
            return x[i].status;
        }
        else
            continue;
    }
    cout << "basteh mor nazar pida nashod" << endl;
    return " ";
}

string viewDakhelStatus(vector<dakhel_shahri> &x)
{
    string user_id;
    cout << "kod rahgiri baste khod ra vared konid" << endl;
    cin >> user_id;
    for (int i = 0; i < x.size(); i++)
    {
        if (user_id == x[i].id)
        {
            return x[i].status;
        }
        else
            continue;
    }
    cout << "basteh mor nazar pida nashod" << endl;
    return " ";
}

int main()
{
    vector<package> pkglist;
    vector<pishtaz> pishlist;
    vector<tipax> paxlist;
    vector<bar_bari> barlist;
    vector<dakhel_shahri> dakhellist;
    fstream outfile;
    readPkgFile(pkglist, outfile);
    insertPkg(pkglist);
    insertPish(pishlist);
    // pkgp -> compute_price();
    savePishFile(pishlist, outfile);
    savePkgFile(pkglist, outfile);
    viewPkgStatus(pkglist);
    viewPishStatus(pishlist);
    viewPaxStatus(paxlist);
    viewBarStatus(barlist);
    viewDakhelStatus(dakhellist);

    int choice;
    do
    {
        cout << "1. sabt  baste\n";
        cout << "2. mohaseb hazineh ersal\n";
        cout << "3. sabt vaziit basteh\n";
        cout << "4. moshahedeh vaziiat basteh\n";
        cout << "5.khroj\n";
        cin >> choice;
        switch (choice)
        {
        case 1:
            int post;
            do
            {
                cout << "1. post adi\n";
                cout << "2. post pishtaz\n";
                cout << "3. post tipax\n";
                cout << "4. post bar bari\n";
                cout << "5. post dakhel shahri\n";
                cout << "6. bargasht be menu ghabl\n";
                switch (post)
                {
                case 1:
                    insertPkg(pkglist);
                    break;
                case 2:
                    insertPish(pishlist);
                    break;
                case 3:
                    insertPax(paxlist);
                    break;
                case 4:
                    insertBar(barlist);
                    break;
                case 5:
                    insertDakhel(dakhellist);
                    break;
                case 6:
                    break;

                default:
                    cout << "adad monaseb bashad";
                    break;
                }

            } while (post != 6);
        case 2:
            int ghimat;
            do
            {
                cout << "1. mohasebe ghimat post adii\n";
                cout << "2. mohasebe ghimat post pishtaz\n";
                cout << "3. mohasebe ghimat post tipax\n";
                cout << "4. mohasebe ghimat post barbari\n";
                cout << "5. mohasebe ghimat post dakhel shahri\n";
                cout << "6. bargasht be menu ghabl\n";
            } while (ghimat != 6);

            switch (ghimat)
            {
            case 1:
                compute_package(pkglist);
                break;
            case 2:
                compute_pish(pishlist);
                break;
            case 3:
                compute_tipax(paxlist);
                break;
            case 4:
                compute_bar_bari(barlist);
                break;
            case 5:
                compute_dakhel_shahri(dakhellist);
                break;
            case 6:
                break;

            default:
                break;
            }
            while (ghimat != 6)
            case 3:
                int vaziiat;
            do
            {
                cout << "1. vaziiat post adii\n";
                cout << "2. vaziiat  post pishtaz\n";
                cout << "3. vaziiat post tipax\n";
                cout << "4. vaziiat  post barbari\n";
                cout << "5. vaziiat  post dakhel shahri\n";
                cout << "6. bargasht be menu ghabl\n";
                switch (vaziiat)
                {
                case 1:
                    setPkgStatus(pkglist) break;
                case 2:
                    setPishStatus(pishlist) break;
                case 3:
                    setPaxStatus(paxlist) break;
                case 4:
                    setBarStatus(barlist) break;
                case 5:
                    setDakhelStatus(dakhellist) break;
                case 6:
                    break;

                default:
                    break;
                }

            } while (vaziiat != 6);
            break;

        case 4:
            int moshahedeh;
            do
            {
                switch (moshahedeh)
                {
                case 1:
                    viewPkgStatus(pkglist);
                    break;
                case 2:
                    viewPishStatus(pishlist);
                    break;
                case 3:
                    viewPaxStatus(paxlist);
                    break;
                case 4:
                    viewBarStatus(barlist);
                    break;
                case 5:
                    viewDakhelStatus(dakhellist);
                    break;
                case 6:
                    break;

                default:
                    break;
                }

            } while (moshahedeh != 6);

        case 5:
            break;

        default:
            cout << "adad monaseb bashad";
            break;
        }
        while (choice != 5)
            ;
        return 0;
    }
}