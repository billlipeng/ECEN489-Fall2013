/*
 * getQuery.cpp
 *
 *  Created on: Nov 24, 2013
 *      Author: Brian
 */

#include "project_analysis_statistics.h"

string getQueryMaxMean(string parameter, string major,char gender,int age, char dominant_hand)
{

	string command = "SELECT ";
	string temp_param = "";

	if (parameter == "right") {
		temp_param = "(score_right_rvlh+score_right_lvrh)";
	}

	if (parameter == "left") {
		temp_param = "(score_left_rvlh+score_left_lvrh)";
	}

	if (parameter == "vertical") {
		temp_param = "(score_right_rvlh+score_left_lvrh)";
	}

	if (parameter == "horizontal") {
		temp_param = "(score_left_rvlh+score_right_lvrh)";
	}

	if (parameter == "total") {
		temp_param = "score_total";
	}

	command = command + " max(" + temp_param + "), avg(" + temp_param + ") ";
	command = command + "FROM data_summary ";

	if (major=="ANY" && gender=='A' && dominant_hand=='A' && age==0) {
		command = command + ";";;
		const char* query = command.c_str();
		return query;
	}

	else command = command + " WHERE " + temp_param + " IS NOT NULL ";

	if (major!="ANY") {
        command = command + " AND major = '" + major + "' ";
	}

	if (gender != 'A') {
		command = command + " AND gender = '" + gender + "' ";
	}

	if (age !=0) {
		stringstream ss_ageminus, ss_ageplus;
		ss_ageminus<<(age-2);ss_ageplus<<(age+2);
		string age_mstr = ss_ageminus.str();
		string age_pstr = ss_ageplus.str();
		command = command + " AND age > " + age_mstr + " AND age < " + age_pstr;
	}

	if (dominant_hand!='A') {
		command = command + " AND dominant_hand = '" + dominant_hand + "' ";
	}

	command = command + ";";
	const char* query = command.c_str();

	return command;
}


string getQueryMedian(string parameter, string major,char gender,int age, char dominant_hand)
{

	string command = "SELECT ";
	string where_param = "";
	string temp_param = "";

	if (parameter == "right") {
		temp_param = "(score_right_rvlh+score_right_lvrh)";
	}

	if (parameter == "left") {
		temp_param = "(score_left_rvlh+score_left_lvrh)";
	}

	if (parameter == "vertical") {
		temp_param = "(score_right_rvlh+score_left_lvrh)";
	}

	if (parameter == "horizontal") {
		temp_param = "(score_left_rvlh+score_right_lvrh)";
	}

	if (parameter == "total") {
		temp_param = "score_total";
	}

	command = command + " avg(" + temp_param + ") FROM (";
	command = command + " SELECT " + temp_param + " FROM data_summary ";

	if (major=="ANY" && gender=='A' && dominant_hand=='A' && age==0) {
		command = command + temp_param + " IS NOT NULL ORDER by " + temp_param + " asc ";
		command = command + "LIMIT 1 OFFSET (SELECT count(" + temp_param + ") FROM data_summary)/2 T ";

		command = command + ";";;
		const char* query = command.c_str();
		return query;
	}

	else command = command + " WHERE " + temp_param + " IS NOT NULL ";

	if (major!="ANY") {
		where_param = where_param + " AND major = '" + major + "' ";
	}

	if (gender != 'A') {
		where_param = where_param + " AND gender = '" + gender + "' ";
	}

	if (age !=0) {
		stringstream ss_ageminus, ss_ageplus;
		ss_ageminus<<(age-2);ss_ageplus<<(age+2);
		string age_mstr = ss_ageminus.str();
		string age_pstr = ss_ageplus.str();
		where_param = where_param + " AND age > " + age_mstr + " AND age < " + age_pstr;
	}

	if (dominant_hand!='A') {
		where_param = where_param + " AND dominant_hand = '" + dominant_hand + "' ";
	}

	command = command + where_param;
	command = command + " ORDER by " + temp_param + " asc ";
	command = command + "LIMIT 1 OFFSET ((SELECT count(" + temp_param + ") FROM data_summary WHERE " + temp_param + " IS NOT NULL " + where_param + ")/2)) T ";



	command = command + ";";
	const char* query = command.c_str();

	return command;
}


