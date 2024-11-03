
#include "images.h"

//------------------------------------------------------------
// List of team names loaded from SD card file PL_teams.txt
// Fixed 20 teams in Premier League +  Select A Team = 21
//------------------------------------------------------------
String arr[21];

void populateListOfTeamsArrayFromSDCard(fs::FS &fs, const char *path) {
  Serial.printf("\nReading getListOfPremierLeagueTeams file: %s\n", path);

  File file = fs.open(path);
  if (!file) {
    Serial.println("Failed to open file for reading");
    return;
  }
  Serial.println("Read populateListOfTeamsArrayFromSDCard from file and store in array: ");

  //Read file and populate an array
  String val1 = "Select A Team";
  val1.trim();
  arr[0] = val1;

  //Get the team names and store in arr
  int indexPosition = 1;
  while (file.available()) {
    String buffer = file.readStringUntil('\n');
    arr[indexPosition] = buffer;
    indexPosition = indexPosition + 1;
  }
  file.close();
}

//------------------------------------------------------------
// Populates the teams dropdown with list of names from SD Card
//------------------------------------------------------------
void populate_teams_dd() {

  // Populate the TEAM dropdown list
  Serial.println("\n\nTeams data from SD card");
  int pos = 1;
  for (String option : arr) {
    Serial.println(option);
    option.trim();
    lv_dropdown_add_option(objects.dd_team_names, option.c_str(), pos);
    pos = pos + 1;
  }
}

//----------------------------------------------------------------
// Get teams data from CSV and store in struct array
// https://github.com/michalmonday/CSV-Parser-for-Arduino/tree/master
//
// Read the data from PL_teams_data_wh_png.csv and store it in list_of_teams
// Headers in CSV files:
// id,team,est,stadium,cupsWon,runnersUp,seasonsInPL,imagePath
//----------------------------------------------------------------
struct PLTeam {
  String id;
  String team;
  String est;
  String stadium;
  String cupsWon;
  String runnersUp;
  String seasonsInPL;
  String imagePath;

  String describeTeam() {
    return id + "," + team + "," + est + "," + stadium + "," + cupsWon + "," + runnersUp + "," + seasonsInPL + "," + imagePath;
  }
} list_of_teams[21];


void populateTeamsStructFromSDCard(const char *path) {

  // parseRow calls feedRowParser() continuously until it reads a
  // full row or until the rowParserFinished() returns true

  //----------------------------------------------------------------
  // LAZY Just use string for everyting:
  //----------------------------------------------------------------
  CSV_Parser cp(/*format*/ "ssssssss", /*has_header*/ true, /*delimiter*/ ',');

  // The line below (readSDfile) wouldn't work if SD.begin wasn't called before.
  // readSDfile can be used as conditional, it returns 'false' if the file does not exist.
  if (cp.readSDfile(path)) {
    char **ids = (char **)cp["id"];
    char **teams = (char **)cp["team"];
    char **ests = (char **)cp["est"];
    char **stadiums = (char **)cp["stadium"];
    char **cupsWons = (char **)cp["cupsWon"];
    char **runnersUps = (char **)cp["runnersUp"];
    char **seasonsInPLs = (char **)cp["seasonsInPL"];
    char **imagePaths = (char **)cp["imagePath"];

    // Serial.println("id,team,est,stadium,cupsWon,runnersUp,seasonsInPL,imagePath");
    // Serial.println("1,Arsenal,1886,Emirates Stadium,3,8,33,Arsenal.png");
    // Serial.println("2,Aston Villa,1874,Villa Park,0,0,30,AstonVilla.png");
    if (ids && teams) {
      //cp.getRowsCount()
      for (int row = 0; row < cp.getRowsCount(); row++) {

        list_of_teams[row].id = ids[row];
        list_of_teams[row].team = teams[row];
        list_of_teams[row].est = ests[row];
        list_of_teams[row].stadium = stadiums[row];
        list_of_teams[row].cupsWon = cupsWons[row];
        list_of_teams[row].runnersUp = runnersUps[row];
        list_of_teams[row].seasonsInPL = seasonsInPLs[row];
        list_of_teams[row].imagePath = imagePaths[row];

        // String line = String(ids[row]);
        // line = line + "," + (teams[row]);
        // line = line + "," + (ests[row]);
        // line = line + "," + (stadiums[row]);
        // line = line + "," + (cupsWons[row]);
        // line = line + "," + (runnersUps[row]);
        // line = line + "," + (seasonsInPLs[row]);
        // line = line + "," + (imagePaths[row]);

        // Serial.print(row);
        // Serial.print(" ");
        // Serial.println(line);

        // Add data to the map
        // d("" + (row + 1), line);

        // Serial.println();
      }
    } else {
      Serial.println("ERROR: At least 1 of the columns was not found, something went wrong.");
    }


    // output parsed values (allows to check that the file was parsed correctly)
    // cp.print();  // assumes that "Serial.begin()" was called before (otherwise it won't work)

  } else {
    Serial.println("ERROR: File called '/PL_teams_data_wh.csv' does not exist...");
  }
}



void add_symbols() {
  //Set symbol
  // lv_image_set_src(objects.img_symbol_2, LV_SYMBOL_OK);
  lv_image_set_src(objects.img_symbol_1, LV_SYMBOL_OK);
  lv_image_set_src(objects.img_symbol_3, LV_SYMBOL_PLUS);
  lv_image_set_src(objects.img_symbol_4, LV_SYMBOL_MINUS);
  lv_image_set_src(objects.img_symbol_5, LV_SYMBOL_UPLOAD);
}


static void set_image_bitmap(uint8_t index) {

  // Delete and recreate with new image (Not needed as I'm not able to load image from SD Card)
  lv_image_cache_drop(NULL);
  lv_obj_delete(objects.img_logo);
  lv_obj_t *obj = lv_image_create(lv_screen_active());
  objects.img_logo = obj;
  lv_obj_set_pos(obj, 191, 87);
  lv_obj_set_size(obj, 115, 125);
  lv_img_set_pivot(obj, 17, 23);
  lv_img_set_zoom(obj, 300);
  lv_obj_set_style_border_width(obj, 1, LV_PART_MAIN | LV_STATE_DEFAULT);

  if (index == 0) {
    lv_image_set_src(objects.img_logo, &img_arsenal);
  } else if (index == 1) {
    lv_image_set_src(objects.img_logo, &img_aston_villa);
  } else if (index == 2) {
    lv_image_set_src(objects.img_logo, &img_bournemouth);
  } else if (index == 3) {
    lv_image_set_src(objects.img_logo, &img_brentford);
  } else if (index == 4) {
    lv_image_set_src(objects.img_logo, &img_brighton);
  } else if (index == 5) {
    lv_image_set_src(objects.img_logo, &img_chelsea);
  } else if (index == 6) {
    lv_image_set_src(objects.img_logo, &img_crystal_palace);
  } else if (index == 7) {
    lv_image_set_src(objects.img_logo, &img_everton);
  } else if (index == 8) {
    lv_image_set_src(objects.img_logo, &img_fulham);
  } else if (index == 9) {
    lv_image_set_src(objects.img_logo, &img_ipswich_town);
  }
  //Other half
  else if (index == 10) {
    lv_image_set_src(objects.img_logo, &img_leicester_city);
  } else if (index == 11) {
    lv_image_set_src(objects.img_logo, &img_liverpool);
  } else if (index == 12) {
    lv_image_set_src(objects.img_logo, &img_manchester_city);
  } else if (index == 13) {
    lv_image_set_src(objects.img_logo, &img_manchester_united);
  } else if (index == 14) {
    lv_image_set_src(objects.img_logo, &img_newcastle_united);
  } else if (index == 15) {
    lv_image_set_src(objects.img_logo, &img_nottingham_forest);
  } else if (index == 16) {
    lv_image_set_src(objects.img_logo, &img_southampton);
  } else if (index == 17) {
    lv_image_set_src(objects.img_logo, &img_tottenham_hotspur);
  } else if (index == 18) {
    lv_image_set_src(objects.img_logo, &img_west_ham_united);
  } else if (index == 19) {
    lv_image_set_src(objects.img_logo, &img_wolves);
  }
}


//------------------------------------------------------------
// Tried to load images directly from SD Card
// But I wasn't able to.
// Not sure if CYD supports this or it could be my one isn't
// setup correctly
//------------------------------------------------------------

/*
  This checks if we are able to read the image file
*/
static void checkIfSDCardIsReady(char val, String path) {
  Serial.println("Path: " + path);
  char buf;
  Serial.println(lv_fs_is_ready(val));
  lv_fs_get_letters(&buf);
  Serial.println(buf);
  lv_fs_file_t f;
  lv_fs_res_t res;
  // res = lv_fs_open(&f, val + ":wink.png", LV_FS_MODE_RD);
  Serial.println("Opening file: " + path);
  res = lv_fs_open(&f, path.c_str(), LV_FS_MODE_RD);
  Serial.println(res);

  // lv_fs_close(&f);
  Serial.println("Opening probably done: " + path);
  Serial.println();
}


char fsIdentifier = 'A';
String drive = String(fsIdentifier) + ":";
static void load_image_sdcard(String path) {

  //NOTE: Loading direct from SD card didn't work :(
  // path = "/Arsenal.bin";
  // path = "wink.png";
  Serial.println("Loading Images: " + path);
  // path.replace("png", "jpg");
  String fullPath = drive + path;
  Serial.println("Check if we can load image from SD");
  checkIfSDCardIsReady(fsIdentifier, fullPath);
  Serial.println("Chceck Finished!");

  Serial.println("Setting image src to : " + fullPath);

  // Delete and recreate with new image (Not needed as I'm not able to load image from SD Card)
  // lv_obj_delete(objects.img_logo);
  // lv_obj_t *obj = lv_image_create(lv_screen_active());
  // objects.img_logo = obj;
  // lv_obj_set_pos(obj, 245, 165);
  // lv_obj_set_size(obj, 60, 60);
  // lv_obj_set_style_border_width(obj, 1, LV_PART_MAIN | LV_STATE_DEFAULT);

  lv_image_cache_drop(NULL);
  lv_image_set_src(objects.img_logo, fullPath.c_str());
  // lv_label_set_text(objects.label_path, fullPath.c_str());

  Serial.println("Load image from SD Done");
}

void listDir(fs::FS &fs, const char *dirname, uint8_t levels) {
  Serial.printf("Listing directory: %s\n", dirname);

  File root = fs.open(dirname);
  if (!root) {
    Serial.println("Failed to open directory");
    return;
  }
  if (!root.isDirectory()) {
    Serial.println("Not a directory");
    return;
  }

  File file = root.openNextFile();
  while (file) {
    if (file.isDirectory()) {
      Serial.print("  DIR : ");
      Serial.println(file.name());
      if (levels) {
        listDir(fs, file.name(), levels - 1);
      }
    } else {
      Serial.print("  FILE: ");
      Serial.print(file.name());
      Serial.print("  SIZE: ");
      Serial.println(file.size());

      // Serial.print(file);
    }
    file = root.openNextFile();
  }
}
