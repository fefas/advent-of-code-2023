#include <gtest/gtest.h>
#include <string>
#include <vector>

#include "../src/07-camel-cards.h"

using namespace std;

namespace {
    Solution_07 *solution = new Solution_07();

    TEST(CamelCards, noHands) {
        ASSERT_EQ(0, solution->part1({}));
    }

    TEST(CamelCards, oneHand) {
        ASSERT_EQ(1403, solution->part1({ { "AAAAA", 1403 } }));
    }

    TEST(CamelCards, rankedMultipleHands) {
        ASSERT_EQ(7231, solution->part1({
            { "12345", 12 },
            { "AAA11", 1505 },
            { "AAAAA", 1403 },
        }));
    }

    TEST(CamelCards, unrankedMultipleHands) {
        ASSERT_EQ(7231, solution->part1({
            { "AAA11", 1505 },
            { "AAAAA", 1403 },
            { "12345", 12 },
        }));
    }

    TEST(CamelCards, unrankedAllHandTypes) {
        ASSERT_EQ(56, solution->part1({
            { "AAA11", 2 },
            { "12AAA", 3 },
            { "1BBAA", 4 },
            { "AAAAA", 1 },
            { "1AA45", 5 },
            { "12345", 6 },
        }));
    }

    TEST(CamelCards, unrankedHandsWithSameType) {
        ASSERT_EQ(455, solution->part1({
            { "77777",  8 },
            { "KKKKK",  2 },
            { "88888",  7 },
            { "99999",  6 },
            { "QQQQQ",  3 },
            { "66666",  9 },
            { "AAAAA",  1 },
            { "TTTTT",  5 },
            { "55555", 10 },
            { "33333", 12 },
            { "44444", 11 },
            { "JJJJJ",  4 },
            { "22222", 13 },
        }));
    }

    TEST(CamelCards, inputSample) {
        ASSERT_EQ(6440, solution->part1({
            { "32T3K", 765 },
            { "T55J5", 684 },
            { "KK677", 28 },
            { "KTJJT", 220 },
            { "QQQJA", 483 },
        }));
        ASSERT_EQ(5905, solution->part2({
            { "32T3K", 765 },
            { "T55J5", 684 },
            { "KK677", 28 },
            { "KTJJT", 220 },
            { "QQQJA", 483 },
        }));
    }

    TEST(CamelCards, myPuzzle) {
        vector<pair<string,int>> input = {
            { "72772", 82 },
            { "8Q278", 230 },
            { "QQJQQ", 42 },
            { "77778", 148 },
            { "QAJ8A", 528 },
            { "87A6K", 976 },
            { "TTTT5", 957 },
            { "QJ4QA", 704 },
            { "6K688", 432 },
            { "93A4Q", 621 },
            { "A66J9", 120 },
            { "J7773", 559 },
            { "88Q88", 196 },
            { "TTT48", 320 },
            { "88887", 995 },
            { "27227", 897 },
            { "JQQ54", 99 },
            { "67666", 646 },
            { "5AT77", 537 },
            { "A96AA", 215 },
            { "AATA8", 211 },
            { "AQQ7J", 306 },
            { "JQ47Q", 499 },
            { "5755J", 11 },
            { "KKKJ5", 814 },
            { "A4527", 479 },
            { "J7744", 26 },
            { "5ATK7", 945 },
            { "K8Q6J", 700 },
            { "67677", 972 },
            { "KJKKJ", 455 },
            { "9A5J6", 338 },
            { "77Q7Q", 421 },
            { "37762", 214 },
            { "Q572K", 561 },
            { "TKTTT", 868 },
            { "75577", 550 },
            { "99666", 584 },
            { "84AK5", 283 },
            { "34Q49", 337 },
            { "AA4AA", 575 },
            { "8K88J", 505 },
            { "44554", 546 },
            { "6JQQT", 757 },
            { "A5Q25", 157 },
            { "23K23", 278 },
            { "28424", 758 },
            { "44QQ4", 183 },
            { "3TTTT", 574 },
            { "5KJ29", 824 },
            { "2A222", 971 },
            { "557TK", 460 },
            { "8TTTJ", 706 },
            { "38T84", 877 },
            { "282J6", 340 },
            { "6A299", 940 },
            { "73JQ7", 573 },
            { "TTT33", 133 },
            { "K6AQT", 297 },
            { "34782", 145 },
            { "2Q4A3", 653 },
            { "884KJ", 533 },
            { "6Q2J3", 689 },
            { "9TQ99", 94 },
            { "JJ6Q6", 693 },
            { "9999K", 397 },
            { "KA896", 734 },
            { "4T444", 962 },
            { "K4T95", 859 },
            { "6T26J", 627 },
            { "JJJ8J", 933 },
            { "555Q5", 5 },
            { "22232", 770 },
            { "2A22J", 424 },
            { "4448Q", 222 },
            { "46436", 776 },
            { "2J2T2", 403 },
            { "8QJ8Q", 393 },
            { "KT39T", 792 },
            { "KQK65", 652 },
            { "T2292", 312 },
            { "K3TAJ", 886 },
            { "259A4", 110 },
            { "88999", 585 },
            { "5T673", 1 },
            { "J29K7", 45 },
            { "KKJKK", 852 },
            { "7AJ8Q", 996 },
            { "24J8J", 605 },
            { "7T667", 748 },
            { "8639J", 269 },
            { "25TA9", 755 },
            { "KQQJQ", 256 },
            { "J6499", 97 },
            { "6T48A", 472 },
            { "95AQ8", 902 },
            { "97979", 319 },
            { "5A555", 238 },
            { "37A7A", 872 },
            { "Q245T", 720 },
            { "37777", 275 },
            { "35533", 989 },
            { "K4AK4", 440 },
            { "T2J48", 181 },
            { "3K857", 205 },
            { "47K65", 991 },
            { "3J383", 975 },
            { "38383", 102 },
            { "6T6TT", 982 },
            { "QAQQ9", 33 },
            { "KK2JK", 400 },
            { "Q6Q6A", 143 },
            { "64836", 336 },
            { "A7A88", 241 },
            { "A9446", 348 },
            { "22252", 225 },
            { "8T944", 362 },
            { "4Q8K2", 318 },
            { "939T9", 394 },
            { "44447", 583 },
            { "334K4", 464 },
            { "2A797", 73 },
            { "KJQQ5", 217 },
            { "77TJ3", 285 },
            { "AAA3A", 407 },
            { "4A2K8", 644 },
            { "TT955", 778 },
            { "QQ8Q8", 175 },
            { "77JKT", 107 },
            { "33833", 65 },
            { "JA8A8", 219 },
            { "867JA", 413 },
            { "4494K", 475 },
            { "42722", 208 },
            { "25535", 30 },
            { "Q282T", 988 },
            { "TTJA3", 170 },
            { "593TA", 889 },
            { "44K44", 127 },
            { "TJJ36", 509 },
            { "Q343A", 843 },
            { "49J53", 784 },
            { "T33T8", 106 },
            { "J799A", 270 },
            { "66956", 862 },
            { "75465", 659 },
            { "55567", 613 },
            { "Q89JA", 361 },
            { "KK548", 529 },
            { "AQAAA", 482 },
            { "658K2", 620 },
            { "7658A", 409 },
            { "66636", 216 },
            { "23846", 961 },
            { "J4JJ4", 150 },
            { "26Q66", 369 },
            { "KKKKA", 832 },
            { "5K55K", 23 },
            { "784QA", 750 },
            { "5A7Q4", 863 },
            { "KQKQJ", 368 },
            { "9JKQA", 309 },
            { "3A6K7", 954 },
            { "2439Q", 707 },
            { "222Q4", 41 },
            { "55255", 549 },
            { "22372", 900 },
            { "A65TJ", 60 },
            { "JA77A", 667 },
            { "QQQQK", 10 },
            { "89466", 548 },
            { "966A6", 15 },
            { "884J8", 177 },
            { "3AKK9", 195 },
            { "5AQQQ", 738 },
            { "J2696", 570 },
            { "AA359", 617 },
            { "5AJ34", 678 },
            { "72222", 837 },
            { "6K325", 596 },
            { "AJAA2", 929 },
            { "TT336", 261 },
            { "7KTTK", 990 },
            { "5A5J5", 675 },
            { "K87J7", 501 },
            { "9QQ93", 334 },
            { "K4747", 20 },
            { "2Q29Q", 305 },
            { "QJ777", 47 },
            { "47478", 869 },
            { "99T99", 759 },
            { "53385", 714 },
            { "QQ5J5", 67 },
            { "6TK44", 209 },
            { "5QA4A", 308 },
            { "82299", 568 },
            { "428QJ", 630 },
            { "44T6T", 386 },
            { "QJJ9T", 190 },
            { "3737K", 69 },
            { "8A738", 339 },
            { "734A9", 579 },
            { "4949T", 540 },
            { "QJ8TT", 492 },
            { "K5AJA", 880 },
            { "2J928", 632 },
            { "24478", 924 },
            { "KQKQK", 891 },
            { "892T8", 78 },
            { "27QK7", 396 },
            { "6JTJ8", 939 },
            { "JJJJJ", 542 },
            { "A2433", 375 },
            { "K38J3", 687 },
            { "TQJQ8", 228 },
            { "64K6T", 875 },
            { "5Q55Q", 342 },
            { "23A49", 699 },
            { "A97J6", 522 },
            { "7TTT4", 454 },
            { "K7J88", 805 },
            { "J3373", 168 },
            { "Q54T6", 331 },
            { "5Q49Q", 728 },
            { "8ATA4", 459 },
            { "TT685", 191 },
            { "9887J", 745 },
            { "24Q79", 282 },
            { "AAQQA", 169 },
            { "A4K3T", 968 },
            { "55559", 703 },
            { "K853J", 801 },
            { "2752A", 448 },
            { "67779", 75 },
            { "3QJ3T", 649 },
            { "46T98", 845 },
            { "8QTT2", 92 },
            { "K5K53", 608 },
            { "TJJ5K", 959 },
            { "8KJ2T", 946 },
            { "87828", 135 },
            { "KKK5K", 903 },
            { "4AJQ4", 847 },
            { "KK7K3", 560 },
            { "44A4Q", 941 },
            { "4A845", 580 },
            { "6Q4QQ", 498 },
            { "A7JAJ", 273 },
            { "K9K9K", 167 },
            { "TTQTT", 478 },
            { "85865", 367 },
            { "TJJ4K", 370 },
            { "63JAA", 964 },
            { "2KA27", 161 },
            { "QJ3KQ", 232 },
            { "2Q332", 865 },
            { "K5855", 233 },
            { "Q66J9", 871 },
            { "9496K", 709 },
            { "22424", 485 },
            { "78KAK", 176 },
            { "KQ26T", 189 },
            { "9JK8T", 223 },
            { "898K3", 474 },
            { "77J8J", 726 },
            { "A6AKA", 624 },
            { "TQ3J6", 155 },
            { "86K8K", 910 },
            { "4Q9T2", 970 },
            { "999KK", 640 },
            { "45JAK", 327 },
            { "9AQT7", 911 },
            { "Q6272", 463 },
            { "99639", 40 },
            { "7T8KA", 648 },
            { "T5K7J", 866 },
            { "A8JAA", 952 },
            { "222KK", 281 },
            { "39598", 288 },
            { "994A4", 721 },
            { "A38JA", 423 },
            { "36AQK", 892 },
            { "49576", 72 },
            { "K999Q", 287 },
            { "T77AA", 885 },
            { "J6J95", 928 },
            { "65596", 354 },
            { "2KA79", 374 },
            { "6333J", 861 },
            { "6553T", 412 },
            { "3674K", 446 },
            { "T46J6", 717 },
            { "6Q26Q", 909 },
            { "JJ444", 556 },
            { "22922", 333 },
            { "K3582", 62 },
            { "TA5K2", 674 },
            { "TQK48", 651 },
            { "6A66A", 610 },
            { "J4664", 251 },
            { "J7Q87", 848 },
            { "KJJ59", 314 },
            { "Q33JQ", 213 },
            { "Q4QQ4", 611 },
            { "J82J5", 402 },
            { "9A889", 588 },
            { "7J26K", 34 },
            { "86T82", 187 },
            { "AA5A2", 353 },
            { "3J5T4", 98 },
            { "A9A99", 873 },
            { "99434", 292 },
            { "9T8T9", 822 },
            { "66J66", 602 },
            { "J5757", 382 },
            { "T5578", 378 },
            { "793A3", 883 },
            { "T9989", 682 },
            { "AKK34", 234 },
            { "82695", 654 },
            { "JAAJA", 272 },
            { "TKT3T", 326 },
            { "2KQ87", 325 },
            { "955K5", 661 },
            { "7AAA7", 212 },
            { "336K3", 384 },
            { "6J696", 122 },
            { "AK2K8", 791 },
            { "QQA46", 296 },
            { "T7354", 199 },
            { "8T894", 359 },
            { "334J4", 236 },
            { "Q6Q6Q", 388 },
            { "J9923", 64 },
            { "2J296", 496 },
            { "Q5JQQ", 151 },
            { "6324A", 126 },
            { "344T4", 953 },
            { "KQT25", 711 },
            { "J557J", 657 },
            { "KKK54", 310 },
            { "K777T", 937 },
            { "8K8K2", 139 },
            { "5J969", 856 },
            { "74974", 539 },
            { "TT696", 948 },
            { "5KQ36", 769 },
            { "AAA72", 295 },
            { "6J39J", 279 },
            { "8868K", 132 },
            { "779J9", 79 },
            { "98Q59", 973 },
            { "QAAA9", 558 },
            { "2222J", 494 },
            { "55757", 255 },
            { "J5T89", 265 },
            { "25AA2", 993 },
            { "63668", 582 },
            { "TQ446", 364 },
            { "44K8J", 247 },
            { "53TA3", 144 },
            { "K5J66", 116 },
            { "85888", 676 },
            { "JJ849", 426 },
            { "293KQ", 566 },
            { "3QQKQ", 979 },
            { "TA83A", 920 },
            { "22J72", 795 },
            { "92527", 171 },
            { "24Q46", 766 },
            { "Q4777", 731 },
            { "393TJ", 820 },
            { "234J3", 965 },
            { "KKJ52", 829 },
            { "8J979", 152 },
            { "J6Q4Q", 673 },
            { "7QJAA", 670 },
            { "7K766", 307 },
            { "9QT86", 207 },
            { "82K88", 555 },
            { "KQKKK", 406 },
            { "664T4", 115 },
            { "A8K34", 487 },
            { "33K33", 202 },
            { "6TK37", 271 },
            { "42744", 544 },
            { "662TT", 420 },
            { "3KK33", 590 },
            { "55589", 963 },
            { "TK779", 767 },
            { "7Q84K", 304 },
            { "37A3A", 619 },
            { "37338", 414 },
            { "88JA8", 25 },
            { "J74Q8", 572 },
            { "QJQ3Q", 664 },
            { "5255J", 322 },
            { "9K6J8", 918 },
            { "576Q6", 730 },
            { "444J3", 19 },
            { "8K663", 804 },
            { "7J7J4", 3 },
            { "4A424", 284 },
            { "A2AAA", 811 },
            { "J553J", 405 },
            { "63KJA", 950 },
            { "JTT89", 554 },
            { "A5TAT", 609 },
            { "77477", 519 },
            { "TJT82", 422 },
            { "77472", 302 },
            { "85T2K", 87 },
            { "A87A5", 27 },
            { "37864", 739 },
            { "KAAAK", 660 },
            { "2T2T2", 321 },
            { "34T43", 390 },
            { "7JK48", 449 },
            { "K4835", 387 },
            { "26622", 410 },
            { "33377", 783 },
            { "84544", 105 },
            { "99588", 708 },
            { "A3T3A", 686 },
            { "7K6Q3", 124 },
            { "33939", 512 },
            { "KK9KK", 839 },
            { "6892Q", 351 },
            { "TT9TT", 335 },
            { "975JA", 587 },
            { "J2449", 392 },
            { "8888J", 436 },
            { "3359A", 365 },
            { "695A9", 36 },
            { "93J8A", 526 },
            { "4T67A", 146 },
            { "2222Q", 825 },
            { "Q7Q2J", 401 },
            { "45447", 300 },
            { "384A3", 77 },
            { "A855J", 101 },
            { "2T8T6", 430 },
            { "JJ6Q2", 250 },
            { "JK22K", 332 },
            { "4K226", 491 },
            { "88QKQ", 51 },
            { "K9KJA", 919 },
            { "9995K", 925 },
            { "24442", 913 },
            { "5KKJ5", 710 },
            { "4T3AA", 723 },
            { "TTT4T", 316 },
            { "JKQ9K", 12 },
            { "44T22", 277 },
            { "876T8", 469 },
            { "66776", 358 },
            { "33382", 691 },
            { "AKKAJ", 930 },
            { "88Q8Q", 114 },
            { "6JQ6Q", 385 },
            { "299J9", 141 },
            { "3AJ9Q", 812 },
            { "2AA72", 43 },
            { "9KKJK", 22 },
            { "Q2Q25", 153 },
            { "5855J", 589 },
            { "K4JK5", 372 },
            { "AKAAA", 347 },
            { "K72J7", 754 },
            { "JTAAA", 356 },
            { "T9AJ2", 48 },
            { "K3348", 779 },
            { "QK3J5", 444 },
            { "63J97", 29 },
            { "A4AQA", 688 },
            { "J3387", 853 },
            { "A9J73", 160 },
            { "54772", 914 },
            { "52325", 149 },
            { "JA2TA", 576 },
            { "774AA", 752 },
            { "544AA", 823 },
            { "52J22", 951 },
            { "93984", 536 },
            { "K5J77", 592 },
            { "7J7J7", 481 },
            { "6328Q", 716 },
            { "7T77A", 761 },
            { "A8QQ9", 174 },
            { "AA8AA", 218 },
            { "89A9A", 629 },
            { "2T82T", 13 },
            { "K6KKK", 985 },
            { "3Q34Q", 380 },
            { "4798T", 803 },
            { "34444", 84 },
            { "T7AQ8", 899 },
            { "T32Q3", 276 },
            { "66363", 477 },
            { "J2992", 942 },
            { "J4555", 904 },
            { "4JTAJ", 598 },
            { "5J955", 227 },
            { "46446", 765 },
            { "79773", 123 },
            { "2AQQQ", 118 },
            { "333J3", 827 },
            { "ATA7T", 162 },
            { "8T882", 159 },
            { "66J6J", 571 },
            { "A88QQ", 363 },
            { "TT999", 581 },
            { "66K6K", 224 },
            { "33AAA", 471 },
            { "KKAAK", 638 },
            { "QJJA9", 55 },
            { "22J2K", 656 },
            { "TJQTT", 760 },
            { "QJ76T", 641 },
            { "T7J9T", 615 },
            { "K4KKK", 198 },
            { "A858J", 978 },
            { "5J555", 567 },
            { "888T3", 834 },
            { "TQQTQ", 647 },
            { "37KJ9", 184 },
            { "57J6A", 530 },
            { "6272A", 376 },
            { "A5AAT", 831 },
            { "KK8K8", 879 },
            { "5665J", 854 },
            { "28665", 32 },
            { "2J6KA", 532 },
            { "55893", 816 },
            { "TT8T6", 346 },
            { "995J9", 379 },
            { "5KQKQ", 958 },
            { "444A7", 24 },
            { "Q5T26", 188 },
            { "7589T", 66 },
            { "9AJAA", 552 },
            { "44KA6", 254 },
            { "8K27T", 91 },
            { "4Q954", 28 },
            { "75QA8", 129 },
            { "55565", 545 },
            { "Q99Q9", 922 },
            { "43999", 836 },
            { "3J33A", 54 },
            { "6J69J", 729 },
            { "27A2J", 881 },
            { "A3854", 194 },
            { "52252", 68 },
            { "J22J2", 204 },
            { "8J778", 231 },
            { "KA8K3", 301 },
            { "22329", 434 },
            { "Q8K3Q", 16 },
            { "88Q8J", 74 },
            { "55TK5", 360 },
            { "6A424", 210 },
            { "88749", 125 },
            { "KQTQT", 685 },
            { "25A5K", 635 },
            { "58KK8", 14 },
            { "2TTTT", 510 },
            { "K7777", 303 },
            { "K5827", 235 },
            { "K565K", 819 },
            { "99969", 266 },
            { "9J276", 999 },
            { "T6K56", 104 },
            { "44K3J", 328 },
            { "T3T32", 39 },
            { "3323Q", 103 },
            { "KKKTT", 563 },
            { "TAT6T", 535 },
            { "T4T44", 350 },
            { "78467", 821 },
            { "66665", 578 },
            { "TT2T2", 898 },
            { "88KA6", 867 },
            { "333Q7", 71 },
            { "8J88J", 932 },
            { "66K66", 551 },
            { "5577T", 927 },
            { "JJ999", 447 },
            { "K3KJJ", 313 },
            { "9T863", 90 },
            { "QT333", 466 },
            { "J799T", 650 },
            { "JTQ34", 381 },
            { "38A33", 690 },
            { "6JT36", 712 },
            { "845A6", 506 },
            { "KKJTK", 259 },
            { "5KK6J", 206 },
            { "4T69J", 86 },
            { "J2625", 311 },
            { "979J9", 818 },
            { "T9J67", 419 },
            { "J2JQQ", 599 },
            { "52K5K", 244 },
            { "8KQ4Q", 462 },
            { "666Q3", 893 },
            { "Q997Q", 997 },
            { "59999", 408 },
            { "KQA88", 618 },
            { "J35T8", 158 },
            { "6AJ66", 6 },
            { "57378", 156 },
            { "QT24T", 586 },
            { "4T546", 850 },
            { "79TA2", 237 },
            { "A7585", 793 },
            { "9TT9Q", 138 },
            { "K4K4J", 154 },
            { "K863K", 345 },
            { "J4675", 887 },
            { "86886", 2 },
            { "455A6", 658 },
            { "A5QQ5", 341 },
            { "69J9J", 165 },
            { "KT592", 178 },
            { "TKTKT", 944 },
            { "3JTT5", 774 },
            { "J5Q24", 404 },
            { "49J99", 415 },
            { "2Q5AQ", 943 },
            { "22226", 109 },
            { "95J9T", 593 },
            { "4K44K", 524 },
            { "428J4", 428 },
            { "A6JA6", 21 },
            { "TT7J7", 601 },
            { "96TJQ", 735 },
            { "4K4TT", 719 },
            { "JAAAA", 983 },
            { "K397A", 357 },
            { "JA348", 200 },
            { "K8888", 732 },
            { "J934K", 488 },
            { "76J37", 201 },
            { "QJTT2", 628 },
            { "356KA", 442 },
            { "99JKK", 547 },
            { "K7J73", 934 },
            { "Q2Q2T", 955 },
            { "KK76K", 782 },
            { "66685", 912 },
            { "34888", 140 },
            { "33533", 809 },
            { "K7KKK", 637 },
            { "67777", 665 },
            { "7KJKK", 468 },
            { "TTT64", 789 },
            { "57QK9", 137 },
            { "52TJ9", 197 },
            { "6JA4A", 626 },
            { "TTT4A", 458 },
            { "8A488", 663 },
            { "445Q4", 513 },
            { "99933", 136 },
            { "95J89", 780 },
            { "5J55J", 787 },
            { "T33T3", 606 },
            { "QJ348", 725 },
            { "T8T88", 753 },
            { "89T98", 248 },
            { "K6J7K", 164 },
            { "T66A9", 59 },
            { "JJQQ3", 502 },
            { "44433", 456 },
            { "49254", 425 },
            { "KK7K7", 810 },
            { "8KAQQ", 186 },
            { "6AQQ9", 185 },
            { "KQ477", 495 },
            { "T77TT", 698 },
            { "68JT9", 798 },
            { "6AJJ2", 343 },
            { "4J448", 949 },
            { "39636", 623 },
            { "4KK8T", 901 },
            { "Q8KQ7", 441 },
            { "39333", 221 },
            { "AAAA9", 672 },
            { "53535", 768 },
            { "77446", 294 },
            { "6A37T", 639 },
            { "32333", 508 },
            { "JJ994", 286 },
            { "A77KA", 705 },
            { "QQQQ3", 9 },
            { "A88KA", 17 },
            { "6JKT3", 418 },
            { "3996J", 864 },
            { "AAJ67", 625 },
            { "2JJ2Q", 718 },
            { "444KQ", 908 },
            { "A8J74", 860 },
            { "T3J3A", 906 },
            { "6J873", 134 },
            { "7Q58Q", 192 },
            { "994A2", 851 },
            { "AA99A", 50 },
            { "4J2K5", 355 },
            { "ATTTA", 504 },
            { "QTTQT", 764 },
            { "85A85", 744 },
            { "JK378", 736 },
            { "828AJ", 799 },
            { "47247", 411 },
            { "78T8T", 226 },
            { "TK888", 756 },
            { "626T2", 315 },
            { "226J6", 438 },
            { "5Q9QQ", 290 },
            { "88886", 742 },
            { "A5TK8", 974 },
            { "KK36K", 330 },
            { "99J96", 562 },
            { "72K72", 203 },
            { "TJK79", 857 },
            { "6AAA4", 52 },
            { "Q3K7T", 813 },
            { "5AJ6Q", 938 },
            { "7JQ66", 398 },
            { "44QQ2", 128 },
            { "8J833", 802 },
            { "46K2J", 894 },
            { "9559J", 317 },
            { "AAKK2", 671 },
            { "J8688", 669 },
            { "9TTK6", 44 },
            { "J5655", 439 },
            { "3K865", 747 },
            { "36AT3", 777 },
            { "A4A4A", 480 },
            { "32JQQ", 936 },
            { "K8T98", 291 },
            { "TQ752", 119 },
            { "J5924", 727 },
            { "QQ7QQ", 643 },
            { "7Q7Q6", 83 },
            { "2JJ99", 267 },
            { "AATJT", 497 },
            { "KQ6Q6", 683 },
            { "355JQ", 878 },
            { "K632Q", 242 },
            { "JQ792", 457 },
            { "A555A", 58 },
            { "255JJ", 53 },
            { "63356", 274 },
            { "66ATT", 520 },
            { "7AK77", 622 },
            { "975A8", 607 },
            { "63333", 833 },
            { "TTTT8", 981 },
            { "KTTKQ", 18 },
            { "JTTJT", 655 },
            { "A34AA", 453 },
            { "5QKJ6", 888 },
            { "85833", 874 },
            { "JJ33T", 531 },
            { "AT222", 260 },
            { "5A5AT", 435 },
            { "388A3", 994 },
            { "32323", 299 },
            { "K4394", 781 },
            { "QA3AA", 773 },
            { "559KK", 111 },
            { "88388", 257 },
            { "87727", 947 },
            { "9JKA9", 416 },
            { "45T8J", 697 },
            { "3AA88", 828 },
            { "JJ43T", 131 },
            { "9K29T", 763 },
            { "6J444", 121 },
            { "9999J", 977 },
            { "3QTA2", 743 },
            { "78439", 905 },
            { "49653", 826 },
            { "AAJAQ", 108 },
            { "8QJ46", 967 },
            { "4TQA8", 484 },
            { "5933J", 7 },
            { "Q6Q5Q", 844 },
            { "4A4J4", 960 },
            { "72TT4", 741 },
            { "45343", 240 },
            { "AAAQ7", 684 },
            { "J2777", 8 },
            { "52226", 323 },
            { "TA472", 38 },
            { "33J3J", 81 },
            { "A5A36", 100 },
            { "A52J2", 76 },
            { "5J7Q5", 645 },
            { "99TTT", 293 },
            { "44AA3", 855 },
            { "89JK8", 603 },
            { "48884", 569 },
            { "77887", 80 },
            { "K5555", 614 },
            { "4T29J", 37 },
            { "4T2T4", 289 },
            { "QQ55Q", 923 },
            { "J564J", 876 },
            { "JQ6KA", 437 },
            { "AA848", 112 },
            { "5A5J3", 35 },
            { "4976J", 916 },
            { "39Q75", 264 },
            { "4K555", 842 },
            { "AA6AA", 921 },
            { "QT2QT", 377 },
            { "855Q8", 85 },
            { "844Q2", 694 },
            { "35555", 702 },
            { "456Q6", 258 },
            { "J2326", 262 },
            { "4Q6A2", 849 },
            { "AA7AA", 882 },
            { "JA94A", 679 },
            { "48888", 538 },
            { "Q7777", 786 },
            { "Q288T", 890 },
            { "5J8Q8", 517 },
            { "84433", 49 },
            { "9889J", 612 },
            { "96969", 246 },
            { "7JTAA", 557 },
            { "3T6J5", 668 },
            { "9KA29", 57 },
            { "A333A", 298 },
            { "2QJQQ", 835 },
            { "9K933", 543 },
            { "J27AK", 525 },
            { "2J525", 366 },
            { "999J3", 352 },
            { "67A69", 840 },
            { "4888K", 56 },
            { "9TJ6T", 577 },
            { "36886", 173 },
            { "5445K", 516 },
            { "A829A", 486 },
            { "TJTTT", 740 },
            { "4JQ94", 493 },
            { "479J3", 681 },
            { "KAA3A", 96 },
            { "77733", 808 },
            { "Q3Q3T", 507 },
            { "T888J", 595 },
            { "7KQ22", 751 },
            { "QQTQQ", 399 },
            { "69666", 31 },
            { "65676", 636 },
            { "87988", 503 },
            { "KJT9K", 917 },
            { "JTA83", 433 },
            { "2622Q", 417 },
            { "2QA75", 489 },
            { "779QA", 371 },
            { "JJJKK", 749 },
            { "43327", 470 },
            { "936A8", 476 },
            { "3KAQ9", 163 },
            { "TQK6K", 89 },
            { "64444", 772 },
            { "94T63", 815 },
            { "AA8A8", 249 },
            { "2Q9A4", 895 },
            { "78QJ3", 452 },
            { "AA5A5", 992 },
            { "T9TT5", 565 },
            { "K39Q7", 935 },
            { "J9TJ9", 662 },
            { "78KKJ", 746 },
            { "A4954", 395 },
            { "7K4K9", 349 },
            { "57KJ3", 467 },
            { "AQA8Q", 984 },
            { "7A234", 523 },
            { "T7777", 443 },
            { "626K3", 701 },
            { "7778A", 179 },
            { "55885", 391 },
            { "7249A", 239 },
            { "55Q56", 229 },
            { "43772", 117 },
            { "JQTQT", 986 },
            { "74J44", 915 },
            { "TTT7T", 431 },
            { "KAATJ", 807 },
            { "T5T55", 518 },
            { "QJ2J8", 329 },
            { "8K8K8", 166 },
            { "AJA99", 450 },
            { "QAJ58", 817 },
            { "69226", 737 },
            { "K2KKK", 677 },
            { "78868", 142 },
            { "2QTTT", 597 },
            { "9A999", 696 },
            { "QQQAQ", 666 },
            { "AAT2A", 63 },
            { "7J777", 93 },
            { "2QQQQ", 956 },
            { "33423", 4 },
            { "J3862", 987 },
            { "A7KKK", 642 },
            { "44777", 541 },
            { "T9647", 46 },
            { "6T929", 465 },
            { "2TTT6", 245 },
            { "J7J7J", 95 },
            { "T66KK", 931 },
            { "689TK", 182 },
            { "T3558", 771 },
            { "6T4A2", 594 },
            { "87887", 998 },
            { "TT445", 564 },
            { "T5QQJ", 695 },
            { "27J4K", 969 },
            { "JQQJQ", 715 },
            { "59873", 180 },
            { "K252K", 858 },
            { "364Q4", 806 },
            { "A972J", 427 },
            { "32372", 61 },
            { "AJ939", 775 },
            { "JQQ7Q", 907 },
            { "95A55", 263 },
            { "88282", 193 },
            { "TJQ2J", 896 },
            { "338J9", 838 },
            { "K4K9A", 490 },
            { "444J4", 796 },
            { "T3A9Q", 147 },
            { "23992", 634 },
            { "3J98T", 515 },
            { "7K477", 680 },
            { "9T7A3", 527 },
            { "8QT88", 130 },
            { "KJ68J", 500 },
            { "5888J", 70 },
            { "384K2", 884 },
            { "76TTT", 790 },
            { "27AA7", 800 },
            { "QQQAA", 591 },
            { "6333A", 846 },
            { "QQ373", 926 },
            { "32232", 172 },
            { "A566J", 692 },
            { "2J4A3", 794 },
            { "TTAQQ", 511 },
            { "584J8", 88 },
            { "6KK76", 383 },
            { "A7AAK", 553 },
            { "33J35", 429 },
            { "5AAAA", 631 },
            { "3AA2K", 724 },
            { "T9Q78", 220 },
            { "TT4TK", 113 },
            { "7553A", 604 },
            { "QQQ9Q", 713 },
            { "Q7Q97", 980 },
            { "4K6KK", 344 },
            { "2J877", 788 },
            { "AQ33J", 1000 },
            { "3888K", 870 },
            { "JA55A", 445 },
            { "66622", 268 },
            { "T5JKK", 616 },
            { "77T56", 521 },
            { "KK8A8", 461 },
            { "K34K4", 733 },
            { "6KJQQ", 797 },
            { "KA329", 600 },
            { "AJAA7", 324 },
            { "99Q8A", 451 },
            { "J7662", 252 },
            { "933J9", 830 },
            { "97797", 373 },
            { "AAA66", 473 },
            { "24TQ8", 243 },
            { "96Q4Q", 633 },
            { "TAAA3", 483 },
            { "QT2A4", 841 },
            { "29929", 966 },
            { "675KT", 785 },
            { "2JJJ5", 280 },
            { "7Q7J6", 253 },
            { "88444", 389 },
            { "Q6996", 762 },
            { "69753", 514 },
            { "7J9AT", 722 },
            { "86866", 534 },
        };

        ASSERT_EQ(248569531, solution->part1(input));
        ASSERT_EQ(250382098, solution->part2(input));
    }
};
