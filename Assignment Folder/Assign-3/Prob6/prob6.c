#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
    float temp;
    float rain;
    float wind;
} Forecast;

typedef struct
{
    char plantType[50];
    char stage[50];
    float estimatedYield;
    Forecast *weatherData;
    int forecastCount;
} Plantation;

typedef struct
{
    char toolName[50];
    char status[20];
    float fuel;
    char schedule[100];
} Machinery;

typedef struct
{
    float nutrients;
    float acidity;
    float pestLevel;
} Monitor;

typedef struct
{
    float lat;
    float lon;
    float soilQuality;
    float waterLevel;
    Plantation *plants;
    Machinery *tools;
    Monitor *monitors;
    int plantCount;
    int toolCount;
    int monitorCount;
} Farm;

typedef struct
{
    char hubName[50];
    Farm *farms;
    int farmCount;
    float predictedYield;
    float resourceAllocation;
    char emergencyResponse[200];
} AgroHub;

// Function Declarations
void setupFarm(Farm *f, int plantCnt, int toolCnt, int monitorCnt);
void setupAgroHub(AgroHub *h, const char *name, int farmCnt);
void insertPlant(Farm *f, const char *type, const char *stage, float yield, int forecastCnt);
void insertTool(Farm *f, const char *name, const char *status, float fuel, const char *schedule);
void insertMonitor(Farm *f, float nutrients, float acidity, float pests);
void showAgroHub(const AgroHub *h);
void releaseFarm(Farm *f);
void releaseAgroHub(AgroHub *h);

int main()
{
    AgroHub hub;
    setupAgroHub(&hub, "Western Hub", 2);

    setupFarm(&hub.farms[0], 2, 2, 2);
    insertPlant(&hub.farms[0], "Rice", "Harvesting", 1500.5, 3);
    insertPlant(&hub.farms[0], "Soybean", "Maturing", 1100.3, 2);
    insertTool(&hub.farms[0], "Seed Planter", "Operational", 75.0, "Weekly check");
    insertMonitor(&hub.farms[0], 5.5, 6.8, 0.4);

    setupFarm(&hub.farms[1], 1, 1, 1);
    insertPlant(&hub.farms[1], "Maize", "Sprouting", 1300.2, 2);
    insertTool(&hub.farms[1], "Irrigation System", "Inactive", 0.0, "Pending repair");
    insertMonitor(&hub.farms[1], 6.8, 7.2, 0.2);

    showAgroHub(&hub);
    releaseAgroHub(&hub);
    return 0;
}

void setupFarm(Farm *f, int plantCnt, int toolCnt, int monitorCnt)
{
    f->lat = f->lon = 0.0;
    f->soilQuality = f->waterLevel = 0.0;
    f->plantCount = plantCnt;
    f->toolCount = toolCnt;
    f->monitorCount = monitorCnt;
    f->plants = (Plantation *)malloc(plantCnt * sizeof(Plantation));
    f->tools = (Machinery *)malloc(toolCnt * sizeof(Machinery));
    f->monitors = (Monitor *)malloc(monitorCnt * sizeof(Monitor));
}

void setupAgroHub(AgroHub *h, const char *name, int farmCnt)
{
    strcpy(h->hubName, name);
    h->farmCount = farmCnt;
    h->farms = (Farm *)malloc(farmCnt * sizeof(Farm));
    h->predictedYield = h->resourceAllocation = 0.0;
    strcpy(h->emergencyResponse, "Plan not defined yet.");
}

void insertPlant(Farm *f, const char *type, const char *stage, float yield, int forecastCnt)
{
    static int plantIdx = 0;
    if (plantIdx >= f->plantCount)
        return;
    Plantation *p = &f->plants[plantIdx++];
    strcpy(p->plantType, type);
    strcpy(p->stage, stage);
    p->estimatedYield = yield;
    p->forecastCount = forecastCnt;
    p->weatherData = (Forecast *)malloc(forecastCnt * sizeof(Forecast));
}

void insertTool(Farm *f, const char *name, const char *status, float fuel, const char *schedule)
{
    static int toolIdx = 0;
    if (toolIdx >= f->toolCount)
        return;
    Machinery *t = &f->tools[toolIdx++];
    strcpy(t->toolName, name);
    strcpy(t->status, status);
    t->fuel = fuel;
    strcpy(t->schedule, schedule);
}

void insertMonitor(Farm *f, float nutrients, float acidity, float pests)
{
    static int monitorIdx = 0;
    if (monitorIdx >= f->monitorCount)
        return;
    Monitor *m = &f->monitors[monitorIdx++];
    m->nutrients = nutrients;
    m->acidity = acidity;
    m->pestLevel = pests;
}

void showAgroHub(const AgroHub *h)
{
    printf("AgroHub: %s\n", h->hubName);
    printf("Predicted Yield: %.2f\n", h->predictedYield);
    printf("Resource Allocation: %.2f\n", h->resourceAllocation);
    printf("Emergency Response: %s\n\n", h->emergencyResponse);

    for (int i = 0; i < h->farmCount; ++i)
    {
        printf("Farm %d:\n", i + 1);
        printf("  Coordinates: (%.2f, %.2f)\n", h->farms[i].lat, h->farms[i].lon);
        printf("  Soil Quality: %.2f, Water Level: %.2f\n", h->farms[i].soilQuality, h->farms[i].waterLevel);
        printf("  Plants:\n");
        for (int j = 0; j < h->farms[i].plantCount; ++j)
        {
            printf("    %s (%s), Yield: %.2f\n", h->farms[i].plants[j].plantType, h->farms[i].plants[j].stage, h->farms[i].plants[j].estimatedYield);
        }
        printf("  Tools:\n");
        for (int j = 0; j < h->farms[i].toolCount; ++j)
        {
            printf("    %s (%s), Fuel: %.2f\n", h->farms[i].tools[j].toolName, h->farms[i].tools[j].status, h->farms[i].tools[j].fuel);
        }
        printf("  Monitors:\n");
        for (int j = 0; j < h->farms[i].monitorCount; ++j)
        {
            printf("    Nutrients: %.2f, Acidity: %.2f, Pests: %.2f\n", h->farms[i].monitors[j].nutrients, h->farms[i].monitors[j].acidity, h->farms[i].monitors[j].pestLevel);
        }
    }
}

void releaseFarm(Farm *f)
{
    for (int i = 0; i < f->plantCount; ++i)
        free(f->plants[i].weatherData);
    free(f->plants);
    free(f->tools);
    free(f->monitors);
}

void releaseAgroHub(AgroHub *h)
{
    for (int i = 0; i < h->farmCount; ++i)
        releaseFarm(&h->farms[i]);
    free(h->farms);
}
