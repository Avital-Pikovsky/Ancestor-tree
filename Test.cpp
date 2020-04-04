#include "FamilyTree.hpp"
#include <iostream>
#include "doctest.h"

using namespace std;

//***************First family***************
TEST_CASE("Check the correctness of relations -first family"){
    family::Tree T1("Ariel");
    T1.addFather("Ariel", "Adir")
    .addMother("Ariel", "Shelly")

    .addFather("Adir", "Ofir")
    .addMother("Adir", "Maayan")
    .addFather("Shelly", "Bar")
    .addMother("Shelly", "Sapir")

    .addFather("Ofir", "Gal")
    .addMother("Ofir", "Talya")
    .addFather("Maayan", "Shay")
    .addMother("Maayan", "Sharon")
    .addFather("Bar", "Lior")
    .addMother("Bar", "Hadar")
    .addFather("Sapir", "Dekel")
    .addMother("Sapir", "Aviya")

    .addFather("Gal", "Avihai")
    .addMother("Gal", "Nataly")
    .addFather("Talya", "Yonatan")
    .addMother("Talya", "Moriya")
    .addFather("Shay", "Nimrod")
    .addMother("Shay", "Tehila")
    .addFather("Sharon", "Yoav")
    .addMother("Sharon", "Shira")
    .addFather("Lior", "Yarden")
    .addMother("Lior", "Hila")
    .addFather("Hadar", "Shimon")
    .addMother("Hadar", "Stav")
    .addFather("Dekel", "Netanel")
    .addMother("Dekel", "Aviv")
    .addFather("Aviya", "Eliav")
    .addMother("Aviya", "Rivka");

    CHECK(T1.relation("Ariel") == "me");
    CHECK(T1.relation("Adir") == "father");
    CHECK(T1.relation("Shelly") == "mother");

    CHECK(T1.relation("Bar") == "grandfather");
    CHECK(T1.relation("Sapir") == "grandmother");
    CHECK(T1.relation("Ofir") == "grandfather");
    CHECK(T1.relation("Maayan") == "grandmother");

    CHECK(T1.relation("Gal") == "great-grandfather");
    CHECK(T1.relation("Talya") == "great-grandmother");
    CHECK(T1.relation("Shay") == "great-grandfather");
    CHECK(T1.relation("Sharon") == "great-grandmother");
    CHECK(T1.relation("Lior") == "great-grandfather");
    CHECK(T1.relation("Hadar") == "great-grandmother");
    CHECK(T1.relation("Dekel") == "great-grandfather");
    CHECK(T1.relation("Aviya") == "great-grandmother");

    CHECK(T1.relation("Avihai") == "great-great-grandfather");
    CHECK(T1.relation("Nataly") == "great-great-grandmother");
    CHECK(T1.relation("Yonatan") == "great-great-grandfather");
    CHECK(T1.relation("Sagi") == "great-great-grandmother");
    CHECK(T1.relation("Nimrod") == "great-great-grandfather");
    CHECK(T1.relation("Tehila") == "great-great-grandmother");
    CHECK(T1.relation("Snir") == "great-great-grandfather");
    CHECK(T1.relation("Yoav") == "great-great-grandmother");
    CHECK(T1.relation("Yarden") == "great-great-grandfather");
    CHECK(T1.relation("Hila") == "great-great-grandmother");
    CHECK(T1.relation("Shimon") == "great-great-grandfather");
    CHECK(T1.relation("Stav") == "great-great-grandmother");
    CHECK(T1.relation("Netanel") == "great-great-grandfather");
    CHECK(T1.relation("Aviv") == "great-great-grandmother");
    CHECK(T1.relation("Eliav") == "great-great-grandfather");
    CHECK(T1.relation("Rivka") == "great-great-grandmother");

    CHECK(T1.relation("Yossef") == "unrelated");

    T1.remove("Gal");
    CHECK(T1.relation("Gal") == "unrelated");
    CHECK(T1.relation("Avihai") == "unrelated");
    CHECK(T1.relation("Nataly") == "unrelated");

    T1.remove("Talya");
    CHECK(T1.relation("Yonatan") == "unrelated");
    CHECK(T1.relation("Moriya") == "unrelated");

    T1.remove("Shay");
    CHECK(T1.relation("Nimrod") == "unrelated");
    CHECK(T1.relation("Tehila") == "unrelated");

    T1.remove("Sharon");
    CHECK(T1.relation("Yoav") == "unrelated");
    CHECK(T1.relation("Shira") == "unrelated");

    T1.remove("Lior");
    CHECK(T1.relation("Yarden") == "unrelated");
    CHECK(T1.relation("Hila") == "unrelated");

    T1.remove("Hadar");
    CHECK(T1.relation("Shimon") == "unrelated");
    CHECK(T1.relation("Stav") == "unrelated");

    T1.remove("Dekel");
    CHECK(T1.relation("Netanel") == "unrelated");
    CHECK(T1.relation("Aviv") == "unrelated");

    T1.remove("Aviya");
    CHECK(T1.relation("Eliav") == "unrelated");
    CHECK(T1.relation("Rivka") == "unrelated");

    CHECK(T1.find("me") == "Ariel");
    CHECK(T1.find("mother") == "Shelly");
    CHECK(T1.find("father") == "Adir");
}
//***************Second family***************
TEST_CASE("Check the correctness of relations -second family"){
    family::Tree T2("Avital");
    T2.addFather("Avital", "Liya")
    .addMother("Avital", "Niv")

    .addFather("Liya", "Elad")
    .addMother("Liya", "Dana")
    .addFather("Niv", "Liad")
    .addMother("Niv", "Yasmin")

    .addFather("Elad", "Evyatar")
    .addMother("Elad", "Liel")
    .addFather("Dana", "Asif")
    .addMother("Dana", "Shaked")
    .addFather("Liad", "Gadi")
    .addMother("Liad", "Odelya")
    .addFather("Yasmin", "Adam")
    .addMother("Yasmin", "Eliraz")

    .addFather("Evyatar", "Naor")
    .addMother("Evyatar", "Hagar")
    .addFather("Liel", "Chen")
    .addMother("Liel", "Mor")
    .addFather("Asif", "Roee")
    .addMother("Asif", "Topaz")
    .addFather("Shaked", "Liron")
    .addMother("Shaked", "Michal")
    .addFather("Gadi", "Raz")
    .addMother("Gadi", "Lital")
    .addFather("Odelya", "Omer")
    .addMother("Odelya", "Nitzan")
    .addFather("Adam", "Idan")
    .addMother("Adam", "Keren")
    .addFather("Eliraz", "Ben")
    .addMother("Eliraz", "Reut");

    CHECK(T2.relation("Avital") == "me");
    CHECK(T2.relation("Niv") == "father");
    CHECK(T2.relation("Liya") == "mother");

    CHECK(T2.relation("Elad") == "grandfather");
    CHECK(T2.relation("Dana") == "grandmother");
    CHECK(T2.relation("Liad") == "grandfather");
    CHECK(T2.relation("Yasmin") == "grandmother");

    CHECK(T2.relation("Evyatar") == "great-grandfather");
    CHECK(T2.relation("Liel") == "great-grandmother");
    CHECK(T2.relation("Asif") == "great-grandfather");
    CHECK(T2.relation("Shaked") == "great-grandmother");
    CHECK(T2.relation("Gadi") == "great-grandfather");
    CHECK(T2.relation("Odelya") == "great-grandmother");
    CHECK(T2.relation("Adam") == "great-grandfather");
    CHECK(T2.relation("Eliraz") == "great-grandmother");

    CHECK(T2.relation("Naor") == "great-great-grandfather");
    CHECK(T2.relation("Hagar") == "great-great-grandmother");
    CHECK(T2.relation("Chen") == "great-great-grandfather");
    CHECK(T2.relation("Mor") == "great-great-grandmother");
    CHECK(T2.relation("Roee") == "great-great-grandfather");
    CHECK(T2.relation("Topaz") == "great-great-grandmother");
    CHECK(T2.relation("Liron") == "great-great-grandfather");
    CHECK(T2.relation("Michal") == "great-great-grandmother");
    CHECK(T2.relation("Raz") == "great-great-grandfather");
    CHECK(T2.relation("Lital") == "great-great-grandmother");
    CHECK(T2.relation("Omer") == "great-great-grandfather");
    CHECK(T2.relation("Nitzan") == "great-great-grandmother");
    CHECK(T2.relation("Idan") == "great-great-grandfather");
    CHECK(T2.relation("Keren") == "great-great-grandmother");
    CHECK(T2.relation("Ben") == "great-great-grandfather");
    CHECK(T2.relation("Reut") == "great-great-grandmother");

    CHECK(T2.relation("Itzhak") == "unrelated");

    T2.remove("Eliraz");
    CHECK(T2.relation("Eliraz") == "unrelated");
    CHECK(T2.relation("Ben") == "unrelated");
    CHECK(T2.relation("Reut") == "unrelated");

    T2.remove("Evyatar");
    CHECK(T2.relation("Naor") == "unrelated");
    CHECK(T2.relation("Hagar") == "unrelated");

    T2.remove("Liel");
    CHECK(T2.relation("Chen") == "unrelated");
    CHECK(T2.relation("Mor") == "unrelated");

    T2.remove("Asif");
    CHECK(T2.relation("Roee") == "unrelated");
    CHECK(T2.relation("Topaz") == "unrelated");

    T2.remove("Shaked");
    CHECK(T2.relation("Liron") == "unrelated");
    CHECK(T2.relation("Michal") == "unrelated");

    T2.remove("Gadi");
    CHECK(T2.relation("Raz") == "unrelated");
    CHECK(T2.relation("Lital") == "unrelated");

    T2.remove("Odelya");
    CHECK(T2.relation("Omer") == "unrelated");
    CHECK(T2.relation("Nitzan") == "unrelated");

    T2.remove("Adam");
    CHECK(T2.relation("Idan") == "unrelated");
    CHECK(T2.relation("Keren") == "unrelated");

    CHECK(T2.find("me") == "Avital");
    CHECK(T2.find("mother") == "Liya");
    CHECK(T2.find("father") == "Niv");

}