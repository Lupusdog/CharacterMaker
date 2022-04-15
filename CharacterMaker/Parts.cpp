#include "CM.h"


vector<vector<string>> info(5);


//追加機能用
/*int selection(){
    cout << "キャラクターメイカーにようこそ！" << endl
    << "要件に合わせて数字を入力してください" << endl
    << "キャラクターの作成:１" << endl
    << "キャラクターの参照:2" << endl
    << "プログラムの終了:3" << endl;
    while(true){
        int number = 0;
        cin >> number;
        if(number == 1 || number == 2 || number == 3){
            return number;
        }
        else{
            cout << "不適切な入力がされています" << endl << "再度入力をお願いします" << endl;
            cin.clear();
            cin.ignore(250,'\n');
        }
    }
}
*/

void charaBuild(){
    static character myChara;
    myChara = getProperties(myChara);
    cout << "キャラクターの名前を決定してください" << endl;
    cin >> myChara.name;
    cout << "名前:" << myChara.name << endl;
    cout << "種族:" << myChara.race << endl;
    cout << "職業:" << myChara.job << endl;
    cout << "特徴:" << myChara.feature << endl;
    cout << "性格:" << myChara.personality << endl;
    cout << "続けてキャラを作成しますか？" << endl;
    cout << "作成する:1 作成しない（終了する）:2" << endl;
    while(true){
        int number = 0;
        cin >> number;
        if(number == 1){
            charaBuild();
        }
        else if(number == 2){
            return;
        }
        else {
            cout << "不適切な入力がされています" << endl << "再度入力をお願いします" << endl;
            cin.clear();
            cin.ignore(250,'\n');
        }
    }
}


character getProperties(character myChara){
    for(int i = 1; i<5; i++){
        int num = (int)info[i].size();
        initRand();
        int random = dice(num);
        switch(i){
            case 1: myChara.race = info[i][random];
                    break;
            case 2: myChara.job = info[i][random];
                    break;
            case 3: myChara.feature = info[i][random];
                    break;
            case 4: myChara.personality = info[i][random];
                    break;
        }
    }
    return myChara;
}

void listProperties(){
    string filePath[4] = {"./texts/race.txt", "./texts/job.txt", "./texts/feature.txt", "./texts/personality.txt"};
    
    for(int i = 0; i < 4; i++){
        ifstream ifs(filePath[i]);
        
        if(ifs){
            string line;
            while(true){
                getline(ifs, line);
                info[i+1].push_back(line);
                if(ifs.eof()) break;
            }
        }
        else
            cout << "エラー発生:製作者にご連絡ください" << endl;
    }
}

void initRand(){
    srand((unsigned int)time(NULL));
}

int dice(int i){
    return rand() % i;
}

