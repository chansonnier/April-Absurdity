#ifndef TOURNAMENT_H
#define TOURNAMENT_H

#include <string>
#include <vector>    // will use this to record player choices (e.g., f,j,j,u,f,f,j,r,...)
using namespace std;

class Competitor;
class Tournament {
    // functions associated with Tournament
    public:
        Tournament(); // default constructor
        
        void setPlayerName(string name);
        
        string getPlayerName();
        
        string getColor(int i); // colors the player's choices according to green=correct, red=incorrect
        
        void setColorWithCode(int index, string colorCode);
        
        void setColor(int i, char choice);
        
        void incrementMatchupNum();
        
        int getMatchupNumber();
        
        string getArrowToRight(int arrowLocation);
        
        string getArrowToLeft(int arrowLocation);
        
        void setPlayersChosenMetric(string input);
        
        string getPlayersChosenMetric();
        
        void setPlayerScore(int score);
        int getPlayerScore();
        
        string getVersus(int index);
        string getCorrect(int index);
        string getIncorrect(int index);
        
        void incrementPlayersUnfamiliarCompanyActions();
        void decrementPlayersSwapsRemaining();
        int getPlayersUnfamiliarCompanyActions();
        
        void decrementPlayersRollActions();
        int getPlayersRollActions();
        
        void decrementPlayersInvestigateActions();
        void incrementPlayersInvestigateActions();
        int getPlayersInvestigateActions();
        
        int getPlayersSwapsRemaining();
        
        string getIntroPicture(int index);
        
        string get9dieResult(int rollValue);
        string get6dieResult(int rollValue);
        
        void lowerThresholdForLVSandSG();
        void badLuck();
        
        int getThresholdForLVSandSG();
        
        
        
    private: 
        
        string playerName;
        
        string playersChosenMetric;
        
        int playerScore = 0;
        
        int numRound = 0;
        
        int matchupNumber = 0;
        
        int playersUnfamiliarCompanyActions = 1; // this will  start at 1 and function as a value to increment until the player runs out of this move, and also as a value to add to the index of the array element to be swapped in
        
        int playersRollActions = 7;
        
        int playersInvestigateActions = 3;
        
        int playersNumSwapsAvailable = 4;
        
        int roll9ThresholdBest = 8; // i.e., have to roll a 9 to get the best result/data. Can be incremented upon certain game events. Reveals both pay ratio ranks
        int roll9ThresholdBetter = 7; // reveals one pay ratio rank
        int roll9ThresholdGood = 4; // reveals one median employee pay
        
        int roll6ThresholdBest = 4; // i.e., have to roll a 4 to get the best result/data. Can be incremented upon certain game events. Reveals one company's ratio
        int roll6ThresholdBetter = 2; // 
        
        
        int thresholdForLVSandSG = 119; // determines the probability that Las Vegas Sands or Scientific Games will be substituted into the game at the next swap. It will decrement by 17 with each player roll, and after 7 rolls, the outcome whose probability is determined by this will be guaranteed
        
        string colors[32] = {"\x1B[33m", "\x1B[33m", "\x1B[33m", "\x1B[33m", "\x1B[33m", 
                             "\x1B[33m", "\x1B[33m", "\x1B[33m", "\x1B[33m", "\x1B[33m", 
                             "\x1B[33m", "\x1B[33m", "\x1B[33m", "\x1B[33m", "\x1B[33m", 
                             "\x1B[33m", "\x1B[33m", "\x1B[33m", "\x1B[33m", "\x1B[33m", 
                             "\x1B[33m", "\x1B[33m", "\x1B[33m", "\x1B[33m", "\x1B[33m", 
                             "\x1B[33m", "\x1B[33m", "\x1B[33m", "\x1B[33m", "\x1B[33m", 
                             "\x1B[33m"};
                             
        string versus[30] = {
                "\x1B[33m                                                         \033[0m", 
                "\x1B[33m                                                         \033[0m", 
                "\x1B[33m                                                         \033[0m", 
                "\x1B[33m                                                         \033[0m", 
                "\x1B[33m                                                         \033[0m", 
                "\x1B[33m                                                         \033[0m", 
                "\x1B[33m                                        ``               \033[0m", 
                "\x1B[33m           ```.                     `'~;;;''`            \033[0m", 
                "\x1B[33m        `:++*'~`          ``    `';|zJt7;~..~`           \033[0m", 
                "\x1B[31m       `~*ZkPwk,`      `',,.` `:zkkkkkj*+;'              \033[0m", 
                "\x1B[31m       `|XUUUUU~`    `'*;|^'.`*UUUUU{<^;`                \033[0m", 
                "\x1B[31m       `^UUUUUU=`   `;jicx,.`^UUUUw+^~                   \033[0m", 
                "\x1B[31m        _UUUUUUy`  `=mIUwI~``wUUU{,!                     \033[0m", 
                "\x1B[31m        `}qAAAAq_``L6Eqq5~~ `yqAqU<_'.`                  \033[0m", 
                "\x1B[31m        `!DDDDDD!'YDDDDE;~   `?DDDDbEfjJc|,`             \033[0m", 
                "\x1B[31m         'RggggR;jggggd:~     `,<;|iLsowbWRjc`           \033[0m", 
                "\x1B[31m         `jQBBBQAQBBBQr^;5k~,    `.,_',:;NBBQ~`          \033[0m", 
                "\x1B[31m          ~QQQQQQQQQQT^,ZQQQN7`   `'!TjbQQQQD;.          \033[0m", 
                "\x1B[31m          `j@@@@@@@@U;.`i@@@@@@QQQ@@@@@@@@Qx^,           \033[0m", 
                "\x1B[31m           ,@@@@@@@Q~'  `cR@@@@@@@@@QBQyc|;;`            \033[0m", 
                "\x1B[31m           `a@@@@@@;~    `,*}fhPXS}*=?=~.`               \033[0m", 
                "\x1B[31m            `zQQN7*~        `'''',__'`                   \033[0m", 
                "\x1B[31m              `'v_                                       \033[0m", 
                "\x1B[31m                 `                                       \033[0m", 
                "\x1B[31m                                                         \033[0m", 
                "\x1B[31m                                                         \033[0m", 
                "\x1B[31m                                                         \033[0m", 
                "\x1B[31m                                                         \033[0m", 
                "\x1B[31m                                                         \033[0m", 
                "\x1B[31m                                                         \033[0m"};
                
        string correct[30] = {
                "\x1B[32m@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\033[0m",
                "\x1B[32m@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@Bg@@@@@@@\033[0m",
                "\x1B[32m@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@#qQ@@@@@@@@\033[0m",
                "\x1B[32m@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@8U8@@@@@@@@@@\033[0m",
                "\x1B[32m@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@8UR@@@@@@@@@@@@\033[0m",
                "\x1B[32m@@@@@@@@@@@@@@@@@@@@@@@@@@@QNQA@@@@@@@@@@@@BUbQ@@@@@@@@@@@@@\033[0m",
                "\x1B[32m@@@@@@@@@@@@@@@@@@@@@@@@@K^'..J@@@@@@#qwmwjkQ@@@@@@@@@@@@@@@\033[0m",
                "\x1B[32m@@@@@@@@@@@@@@@@@@@@@@@@@B~   w@@@Qx~,'````'iQ@@@@@@@@@@@@@@\033[0m",
                "\x1B[32m@@@@@@@@@@@@@@@@@@@@@@@@@@@I.`Q@@q!:'.``    `'q@@@@@@@@@@@@@\033[0m",
                "\x1B[32m@@@@@@@@@@@@@@@@@@@@@@@@@@@@~ i@Q=;,'.``     `,@@@@@@@@@@@@@\033[0m",
                "\x1B[32m@@@@@@@@@@@@@@@@@@@@@@@@@@@@T``#Q*;_,'.``` ``.,Q@@@@@@@@@@@@\033[0m",
                "\x1B[32m@@@@@@@@@@@@@@@@@@@@@@@@@@@@D' ;Qt>;~:,''...',Y@@@@@@@@@@@@@\033[0m",
                "\x1B[32m@@@@@@@@@@@@@@@@@@@@@@@@@@@@@i. '}ji=!;;~~~;<b@@@@@@@@@@@@@@\033[0m",
                "\x1B[32m@@@@@@@@@@@@@@@@@@@@@@@@@@@@@Q;` `;^~;^?IyU#@@@@@@@@@@@@@@@@\033[0m",
                "\x1B[32m@@@@@@QWbXPXDQ@@@@@@@@@@@@@@QKz,.```   .!*PQ@@@@@@@@@@@@@@@@\033[0m",
                "\x1B[32m@@@@@gKUXUUUU6D@@@@@@@@@@@@NAqy;'``     `   ~6@@@@@@@@@@@@@@\033[0m",
                "\x1B[32m@@@@@@@@W6U6666d@@@@@@@@@@Rqqqc~'`     `+Sx!` w@@@@@@@@@@@@@\033[0m",
                "\x1B[32m@@@@@@@@@QK666AAb@@@@@@@QbqqqU+_'`    `~Q@Q~ .B@@@@@@@@@@@@@\033[0m",
                "\x1B[32m@@@@@@@@@@@bAAAAAd@@@@@QqqqqbP;,'``   `^@Q7``W@@@@@@@@@@@@@@\033[0m",
                "\x1B[32m@@@@@@@@@@@@KAAqqqD@@@8AqAqK@c~,'.``` `:;.``y@@@@@@@@@@@@@@@\033[0m",
                "\x1B[32m@@@@@@@@@@@@QKqqqAqRQDqqAAqQQ!,,''.````~!'`7@@@@@@@@@@@@@@@@\033[0m",
                "\x1B[32m@@@@@@@@@@@@@QqqAAAAqqqqqqNQ!'` .~!,.` `~oQ@@@@@@@@@@@@@@@@@\033[0m",
                "\x1B[32m@@@@@@@@@@@@@@Bqqqqqqqqqqb@?'`  'K@A;'`  ;@@@@@@@@@@@@@@@@@@\033[0m",
                "\x1B[32m@@@@@@@@@@@@@@@RqqqqqqqqqQN,.  `t@@@X;'   z@@@@@@@@@@@@@@@@@\033[0m",
                "\x1B[32m@@@@@@@@@@@@@@@@KqqqqqqqR@d:. `;@@@@@E~`  ;@@@@@@@@@@@@@@@@@\033[0m",
                "\x1B[32m@@@@@@@@@@@@@@@@NqqqqqqK@@D~'`.o@@@@@h;'.'D@@@@@@@@@@@@@@@@@\033[0m",
                "\x1B[32m@@@@@@@@@@@@@@@@@KqqqDQ@@@7,.`'B@@@@Qi;,,!gRQ@@@@@@@@@@@@@@@\033[0m",
                "\x1B[32m@@@@@@@@@@@@@@@@@RqgQ@@N~'''``'X@@@@q!~,,_'``N@@@@@@@@@@@@@@\033[0m",
                "\x1B[32m@@@@@@@@@@@@@@@@@@@@@@@Q<'._*h#@@@@@@Q#byc<=f@@@@@@@@@@@@@@@\033[0m",
                "\x1B[32m@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\033[0m"};
        
        string incorrect[30] = {
                "\x1B[31m                                                            \033[0m",            
                "\x1B[31m                                               `            \033[0m",
                "\x1B[31m                                        ````````..`         \033[0m",
                "\x1B[31m                                       `''''.'''',,`        \033[0m",
                "\x1B[31m                                       `~~~~~~~~~;;.        \033[0m",
                "\x1B[31m                                        ;++^^^^++=!         \033[0m",
                "\x1B[31m                                         ,<7777c=~          \033[0m",
                "\x1B[31m                             `;``````   ```:^=^,``          \033[0m",
                "\x1B[31m        `~sj+,              'Xf.`.~i+;_:~,'''''''','``      \033[0m",
                "\x1B[31m      .cRQQQQQKc'          'RRi^;+nq5Z{i?^~:,,,:_~;!~_'`    \033[0m",
                "\x1B[31m    .zQQQQQQQQQQQR|`      +QQQ5SDQQ@Rv';j7^;;;;;;;~:;^+~'   \033[0m",
                "\x1B[31m   `DQQQQQQQQQQQQQQD^`  'fQ@QQQ@@QQQQQ, ;o*^!;;;;;'`':~!.   \033[0m",
                "\x1B[31m   ,7m&@QQQQQQQQQQQQQB+zQQQQQQQQQQQQX:  `z|;;~~__~;!~;;`    \033[0m",
                "\x1B[31m      `;sb@QQQQQQQQQ@@@QQQQQQQQQQQQ7     |c;~:,,,,~>;~      \033[0m",
                "\x1B[31m          '7B@QQQQQQQQ@QQQQQQQQQ@D,      +j|=+^^^^=c'       \033[0m",
                "\x1B[31m            `?QQQQQQQQQQQQQQQQ@Q^`       ,n<^!;;;;^c`       \033[0m",
                "\x1B[31m              `}@@QQQQQQQQ@@@@7`          7+!^++^^^;        \033[0m",
                "\x1B[31m              ;g@@@@@@@@@@@@@@q_          *;,:!*^!!,        \033[0m",
                "\x1B[31m           .cD@@@@@@@@@@@@@@@@@@qL.       ^!'''_~~;`        \033[0m",
                "\x1B[31m        `~nQ@@@@@@@@@@@@@@@@@@@@@QQj;`    '|~,'''',`        \033[0m",
                "\x1B[31m      'SQQ@@@@@@@@@@@@g@@@@@@@@@@@@Q@QdJ,  '|L!~,''','`     \033[0m",
                "\x1B[31m     '8Q@@@@@@@@@@@@Q7`|Q@@@@@@@@@@@@@@@P`  .Yyz>;~~;~,'    \033[0m",
                "\x1B[31m    ``c@@@@@@@@@@@@m,...,sQ@@@@@@@@@@@@Q=```;wn}o5jc;:,'    \033[0m",
                "\x1B[31m ``````*Q@@@@@@@@R<,,,,,,,!X@@@@@@@@@@N^''''!XjJyS;i~'''`   \033[0m",
                "\x1B[31m```.'',:!m@@@@QDJi|*<<>>><*|7w#@@@@@&w=^;;;;<f!~;+*L>^;;.`` \033[0m",
                "\x1B[31m```.'',,~;*XwIL?<=+^^^^^^^^+=<|cZq6t<+!;;~~~~>*><|L*sJ|;.`` \033[0m",
                "\x1B[31m``````...'''''',,,,,,,,,,,,,,,,,,,,'''''''''.'..'.....````  \033[0m",
                "\x1B[31m````````````.........''''....'........``````````````````    \033[0m",
                "\x1B[31m``````````````````````````````````````````````````          \033[0m",
                "\x1B[31m         ````````````````````````````````                   \033[0m"};
        
        string introPicture[39] = {
"\x1B[33m                                                                                                                                                                                                      \033[0m",
"\x1B[33m                                                                                                                                                                                                      \033[0m",
"\x1B[33m                                                                                                                                                            `,::,,,,,:::,,,,,,,::::,,,.               \033[0m",
"\x1B[33m                                        ``.':~~~,.``                                                                                                       `'k@@@@@@@@@@@@@@@@@@@@@@@Z'               \033[0m",
"\x1B[33m                                    ``:|yb&Q@@@@QQRmi$$|||||||||$$||$$$|$$||||||$$$$|||$$|||||$$$||||$||||||$$||||||||$$$||$$$||$$$||||$|||$$$$$$$$|||$$$$$$$Q@@@@@@@@@@@@@@@@@@@@@@@|.               \033[0m",
"\x1B[33m                                  `.LKQ@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@bkXXXXXXXXXXXXb@@@@B~`               \033[0m",
"\x1B[33m                                 `;X@@@@Q$qEZooaEARQ@@@@@@@@@QgW8W8N@@@@QW8888WQ@@@@QWW88WQ@@@@@#88888888N@@@@@@@QWW88WWQ@@@@Q88WN@@@Q88gQ@@@@@@@@@@@@@@@@@@@@@@Qj}kKbbbbbbbKbbW@@@@a'                \033[0m",
"\x1B[33m                                'x@@@QDojffffjfffjjja$@@@@@@@!      a@@Q~     `D@@@q`     .Q@@@6          'j@@Qs_        ;D@Q~   _Q@Q,   z@@@@@@g{}ffffffffffjjjjf5Q@@@@@@@@@@@@@@@Q+`                \033[0m",
"\x1B[33m                               'z@@@QZffffffffffff}jf}PQ@@@@W`      w@@v      ;@@@Q~  `   'Q@@@i   `;^~    ;@@z    ~^~    }@b`   7@@U   `D@@@@@@UuSBQQQQQQQQQQQNyfSW#NNNNNNNN8Q@@@@R,`                \033[0m",
"\x1B[33m                              `;Q@@@mf}fjffffffffff}}ffPQ@@@n       X@K`      {@@@7   ;   'Q@@Q,   ;@@h    }@@~   _Q@a   .W@i   `D@@$   ;@@@@@@Qy}K@@@@@@@@@@@@Qoaoooaoooo5yyyD@@@@s'                 \033[0m",
"\x1B[33m                              .$@@@Quff}}}fff}f}}f}}}fjjQ@@@;   '   KQ~  ,`  `g@@D`  ;J   ,Q@@k    Y@@$   `g@6    7@@k$$$E@Q,   ~Q@Q,   Y@@@RDdkjjB@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@Q!`                 \033[0m",
"\x1B[33m                              .z@@@Q}}}fffjfjfff;f}fjfQ7j@@D`  `=  `Rv  ,+   !@@Q;   A7   ~@@@*    *sz.   !@@L   `D@@@@@@@@U    `''.   `8@@QhwEjfw@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@K,`                 \033[0m",
"\x1B[33m                              .>@@@@j}ffjfjjj}zjjjffff}iQ@@z   !t  `q` `j_   y@@I   '@=   ;@@Q'         `;K@Q,   ~@@@@@@@@@|           ^@@@@@@Qy}D@@@@@@@@@@@@86AqAU6666666A6Q@@@@J.                  \033[0m",
"\x1B[33m                              `,k@@@$Ijfjffff}f}jjj}}fjEQ@Q~   nz  `^  <X   .8@R.   ;y,   !@@o    !$`   v@@@P    Y@@o77zg@Q,   ;gWk`   y@@@@@@b}yQ@@@@@@@@@@@QE}ZqKKKbbbbbbKbQ@@@Q!`                  \033[0m",
"\x1B[33m                               `_b@@@QUjf}}fff}}ff}}yqQ@@@X`  'Qi     ~Q*   *@Q~          +@@!   'Q@=   ~Q@@+   .#@D`   K@y    o@@}   'Q@@@@@Qa}fjjjjjjjffffjf{}g@@@@@@@@@@@@@@@@E'                   \033[0m",
"\x1B[33m                                `;&@@@@QRhy}ffff}jEDQ@@@@@|   *@|    `qQ,   h@J   `7oz`   *@g`   *@@S    X@B.   `;!,   _Q@^   'Q@@;   $@@@@@@@QQQQQQQQQQQQQQQEfjDNB&&&&&&&##@@@@@L.                   \033[0m",
"\x1B[33m                                 .=Q@@@@@@@QQ&BQQQ@@@@@@@Q'  `h@=    i@S   ,QD.   <@@q    L@s    X@@Q    *@Qz'       `ig@g.   *@@R`   U@@@@@@@@@@@@@@@@@@@@@QwyyyyyyyyyyyyymQ@@@#~`                   \033[0m",
"\x1B[33m                                  'v@@@@@@@@@@@@@@@@@@@@@@qqA$@@gAqqb@@#qqbQ@BqqqDQ@@Qqqqq#@8qqqg@@@@bqqK#@@@QKqqqqKKQ@@@QqqqdQ@@QqqKD@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@a'                    \033[0m",
"\x1B[33m                                   ,g@@@@@@@@@@@@@@@@@@RwmmD@@QUwmEW@@@8W888NQ@@@@Q888WWQ@@@@Q888WWN@@@@@QWW8888888Q@@@@QNW8N@@@@Q888Q@@QWW88888W8Q@@@@N888888Q@@@@@@Q888888#@@@Q$,`                  \033[0m",
"\x1B[33m                         .',,,,,,,,:<Q@@@@@@@@@@@@@@@Rniiu$@QwTi$o&@@@m      ^@@@W.     L@@@@^      =@@@@;         `>8@@$   `k@@Q'   f@N.         7@Q}'       .zQ@@d|.       ~X@@@U,`                 \033[0m",
"\x1B[33m                        `^Q@@@@@@@@@@@@@@@@@@@@@@@@gziioQ@Nyii7XQ@@@@@!      =@@Q~     `d@@@z   `   +@@@6    :^^,    z@B.    ^@@y   'B@x    ;^^^^LQQ_   ,^^.    K@U    ;^;    ;$kQy'                  \033[0m",
"\x1B[33m                        '}@@@@@@@@@@@@@@@@@@@@@@@@#qAq#@@QqqqbQ@@@@@@g`      *@@T      ~Q@@D`  ';   *@@@L   `K@@$   `R@j     `g@!   =@@;   ,Q@@@@@@q`  `K@Q;`..+@@|   `@@A...'y@@@*.                  \033[0m",
"\x1B[33m                       `:g@@@NwmwEEEEEEwwwwmD@@@@@@@@@@@@@@@@@@@@@@@@{   '.  L@K` `,   I@@@;   tr   |@@Q,   ;@@Q'   ;@@^      zg`   w@b`   <QQQQ@@@L   _QQQQQQ@@@Q'   ~QQQ#Q@@@@@W:`                  \033[0m",
"\x1B[33m                       .=@@@@QRRRR$$$$$RDE}fRQQQQQQQQQQQQQQ@@@@@@@@@@;   <.  7Q~  ^~  `$@@}   ,Q~   T@@k    J@@E    }@g`   `  ~7   'Q@v     ```:Q@@~    `````^D@@U     ````'7Q@@@o'                   \033[0m",
"\x1B[33m                       '5@@@@@@@@@@@@@@@@U}}jjjjjjjjjjjjfjjq@@@@@@@@@`  `a`  J7  'j`  !@@g.  `SQ'   s@@<   `$@@>   `8@{   'i   `   |@@_   ```.'S@@@W<.````    ,Q@@w~```.`    7@@@<.                   \033[0m",
"\x1B[33m                      `_#@@@QBBBBBQQQQQBg5fUQQQQQQQQQQQQqjjN@@@@@@@@R   ;D`  !.  aT   j@@r   .n7`   {@Q'   !@@Q'   ^@@;   $N.      X@@    7@@@@@@@QQBgQ@Q6`   |@QQBNgQ@@|    6@@8_`                   \033[0m",
"\x1B[33m                      .$@@@@KwwwwwwwwwwwwmEQ@@@@@@@@@@@@PfwQ@@@@@@@@i   ob      iQ'  'Q@z           j@y    S@@f    h@@    U@|     ~@@E   `g@@@@@@A`   d@@$   `b@|   `$@Q,   ;@@@}'                    \033[0m",
"\x1B[33m                     `'6@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@Qj{a6A6N@@@@Q,  'BU     _QE   *@D`   +ww+    Z@!    ~;;.   'Q@A   ~Q@q`    J@@<   `;;;;;x@i    ~;;`   ~QQ,   `~;:    }@@Q^`                    \033[0m",
"\x1B[33m                     `;Q@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@dfjX66UQ@@@@k   *@P    `6@*   k@;   ,B@@7    E$`         'L$@@i   7@@Q~   `D@Q'         j@b;        '$N@QI'       `;yQ@@$,`                    \033[0m",
"\x1B[33m                     'z@@@@AEPEEEEEEEEEEwU@@@@@@@@@@@@Qm}X@@@@@@@@@QqKdQ@QAqqqN@@RqKD@QKqqqQ@@@#qqqKQQqqqqqqqqAKQ@@@@$qqDQ@@@QKKqd@@QqqqqqqqqqD@@@@DqqqqqqDQ@@@@@QKqqqqqqN@@@Qh!`                     \033[0m",
"\x1B[33m                    `,d@@@@gRR$$$$$$RRqjfXQ@@@@@@@@@@Q$f}g@@@@@@QbUXq@@g6UUU#@QKUUdQ@$XXU&@@QbUUUqQ@NXUUUUUUAQ@@@@@DUXU8@@@@$6UqQ@QqXXUUUUXqQ@@@@QbXXU6#@@@@@@@@$UUUXAQ@@@@@X!.`                      \033[0m",
"\x1B[33m                    `^Q@@@@@@@@@@@@@@@gffjjjjjjjjjffjj}{5Q@@@@Q67LvXQgjiL$o#Q67L7UQBaiijN@QX7LLiSB8y$iiiiLTEQ@@@@dtiLz8@@@DYivwQQU7LLiLLL$SQ@@@Q67iiLzN@@@@@@@gfLLLioQ@@@@k!.                         \033[0m",
"\x1B[33m                    .u@@@@QQBQQQQQQQB&EfaNQBQBBBBBBBQQQ#Q@@@@@Q888Q@@8W88Q@@QW8NQ@@NW8Q@@@BW888Q@QN8NNNN88Q@@@@@QNN8NQ@@@Q888Q@@Q88888888Q@@@@@QNNNW8Q@@@@@@@QN888WQ@@@@E!.                           \033[0m",
"\x1B[33m                    _N@@@QmmmSSSSSSSSSSSR@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@QP:`                             \033[0m",
"\x1B[33m                   `|@@@@@@@@@@@@@@@@@@@@@@@QjInnnIIYnnIIIsssssIIIIIIIYnnYIIYYIsYYIIIYssYYIIuYIsIxIYsssssxIsxInnnIxsIIIIIxsIIIssssssssIIsIYIsxsYsxxssIYYYYIIIYnYssssx!`                               \033[0m",
"\x1B[33m                   .a@@@@@@@@@@@@@@@@@@@@@@@X'`                                                                                                                                                       \033[0m",
"\x1B[33m                   .,:::,:::::::,,::::::::::,`                                                                                                                                                        \033[0m",
"\x1B[33m                                                                                                                                                                                                      \033[0m",
"\x1B[33m                                                                                                                                                                                                      \033[0m"};



};

#endif

// int function(competitor, i){  // 
//     if (playerChoice = correct){
        
//     }
    
// }



/* would like to be able to do things like:

- tourney.config()     -sets things like playerName, metric, industries/all
- tourney.nextMatchup()
    does this take arguments, e.g., competitor[i] and competitor[i+1]?
- tourney.checkModifierEvents()          this should probably be part of nextMatchup()
- tourney.showChoiceResult()          would add the +1, green/red color to the competitor's name
- tourney.reveal


*/

