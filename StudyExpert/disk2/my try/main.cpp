/****************************************************************************************************************
1. insert_data(char* filename, char *data,int offset, int size)
	data를 filedata에서 offset 부터 저장, 뒤에 있는 데이터는 뒤로 밀기.
	ex) data - "aaaaa", filedata[badsf] - "bbbbbbbbb"
		insert_data("badsf", data, 3, 5);
		>>>>>>>>>> filedata[badsf] - "bbbaaaaabbbbbb"

2. delete_data(char* filename, int offset, int size)
	filedata를 offset에서 size 만큼 data 제거, 제거후 데이터 앞으로 당기기.
	ex) filedata[badsf] - "bbbbcccccc"
		delete_data("badsf", 3, 5);
		>>>>>>>>>> filedata[badsf] - "bbbcc" 
3. user.cpp는 메모리 4mb 사용 가능하다. 중요!!!!!!! 

4. 점수가 낮을수록 좋다.
****************************************************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include<memory.h>
#include<time.h>

static char	Disk[16][1024][1024];
static char _data[4096];
static char	file_name[100][16];
static char file_data[100][1024 * 1024];
static int	file_size[100];
static int	disk_size;
static int	disk;
static int	seed = 3;
static int	score = 0;

extern void init();
extern void insert_data(char* filename, char *data, int offset, int size);
extern void delete_data(char* filename, int offset, int size);
extern void verify_data(char* filename, char *data, int offset, int size);

void change_disk(int num) {
	disk = num;
	return ;
}

void _build() {
	init();
	disk_size = 0;
	disk = 0;
	for (int i = 0; i < 100; i++) {
		file_size[i] = 0;
		for (int j = 0; j < 16; j++)
			file_name[i][j] = 'A' + rand() % 26;
	}
}

void read_disk(int sector, char* data) {
	if (sector < 0 || sector >= 1024)
		return;
	memcpy(data, Disk[disk][sector], 1024);
}

void write_disk(int sector, char* data) {
	if (sector < 0 || sector >= 1024)
		return;
	memcpy(Disk[disk][sector], data, 1024);
}

void _insert() {
	int index = rand() % 100;
	int offset = rand() % (file_size[index] + 1);
	int data_size = rand() % 4096 + 1;
	for (int i = 0; i < data_size; i++)
		_data[i] = rand() % 26 + 'A';
	insert_data(file_name[index], _data, offset, data_size);
	for (int i = file_size[index] - 1; i >= offset; i--)
		file_data[index][i + data_size] = file_data[index][i];
	file_size[index] += data_size;
	disk_size += data_size;
	for (int i = 0; i < data_size; i++)
		file_data[index][offset + i] = _data[i];
}
void _delete() {
	int index = rand() % 100;
	int offset = rand() % (file_size[index] + 1);
	int data_size = rand() % 4096 + 1;
	if (offset + data_size > file_size[index])
		data_size = file_size[index] - offset;
	for (int i = offset; i < file_size[index] - data_size; i++)
		file_data[index][i] = file_data[index][i + data_size];
	delete_data(file_name[index], offset, data_size);
	file_size[index] -= data_size;
	disk_size -= data_size;
}
void _verify(int num) {
	int index = num;
	int offset = rand() % (file_size[index] + 1);
	int data_size = rand() % 4096 + 1;

	if (offset + data_size > file_size[index])
		data_size = file_size[index] - offset;
	verify_data(file_name[index], _data, offset, data_size);
	if (memcmp(file_data[index] + offset, _data, data_size) != 0) {
		score += 1000000;
	}

}
int main() {
	srand(seed);
	int start = clock();
	for (int t = 0; t < 1; t++) {
		_build();
		while (disk_size < 10 * 1024 * 1024) {
			switch (rand()%10){
			case 0:
			case 1:
			case 2:
			case 3:
			case 4:
			case 5:
				_insert();
				break;
			case 6:
			case 7:
			case 8:
			case 9:
				_delete();
				break;
			}
		}
		for (int i = 0; i < 100; i++)
			_verify(i);
	}
	score += (clock() - start);
	printf("score = %d\n", score);
}