/*
Project 5: Part 1 / 4
 video Chapter 2 - Part 12

 Create a branch named Part1

Purpose:  This project continues developing Project3.
       you will learn how to take code from existing projects and migrate only what you need to new projects
       you will learn how to write code that doesn't leak as well as how to refactor. 

NOTE: there are 2 sets of instructions:
       One for if you completed project 3
       One for if you skipped project 3.

 Destructors

===============================================================     
 If you completed Project 3:
 
 1) Copy 3 of your user-defined types (the ones with constructors and for()/while() loops from Project 3) here
    Choose the classes that contained nested classes.  Include the nested classes when you copy them over.

 2) move all of your implementations of all functions to OUTSIDE of the class.

 3) add destructors
        make the destructors do something like print out the name of the class.
===============================================================
If you skipped Project 3:
write 3 UDTs below that EACH have: 
        5 member variables
            the member variable names and types should be relevant to the work the UDT will perform.
            pick properties that can be represented with 'int float double bool char std::string'
        3 member functions with an arbitrary number of parameters
            give some of those parameters default values.
        constructors that initialize some of these member variables
            the remaining member variables should be initialized in-class
        for() or while() loops that modify member variables
 1) 2 of your 3 UDTs need to have a nested UDT.
    this nested UDT should fulfill the same requirements as above:
        5 member variables  
        3 member functions
        constructors and loops.
        
 2) Define your implementations of all functions OUTSIDE of the class. 
 NO IN-CLASS IMPLEMENTATION ALLOWED
 3) add destructors to all of your UDTs
        make the destructors do something like print out the name of the class.
===============================================================

 4) add 2 new UDTs that use only the types you copied above as member variables.

 5) add 2 member functions that use your member variables to each of these new UDTs

 6) Add constructors and destructors to these 2 new types that do stuff.  
        maybe print out the name of the class being destructed, or call a member function of one of the members.  be creative
 
 7) copy over your main() from the end of Project3 
        get it to compile with the types you copied over.
        remove any code in main() that uses types you didn't copy over.
 
 8) Instantiate your 2 UDT's from step 4) in the main() function at the bottom.
       call their member functions.
 
 9) After you finish, click the [run] button.  Clear up any errors or warnings as best you can.

 you can resolve any [-Wdeprecated] warnings by adding -Wno-deprecated to list of compiler arguments in the .replit file. all of the "-Wno" in that file are compiler arguments.
 You can resolve any [-Wpadded] warnings by adding -Wno-padded to the list of compiler arguments in the .replit file. all of the "-Wno" in that file are compiler arguments.

 Ignore the Atomic.h and LeakedObjectDetector.h files for now.
 You will use those in Part 3 of this project.

 */
#include <string>
#include <iostream>
#include <cmath>
/*
 copied UDT 1:
 */

struct SaucerSection
{
    SaucerSection();
    ~SaucerSection();

    bool attached;
    int decks;
    float shieldStrength;
    std::string shieldType;
    unsigned int personnelOnboard;

    bool detachSaucer();
    float firePhasers(int pattern, float power);
    float raiseShields();

    struct Bridge
    {

        Bridge();
        ~Bridge();

        std::string commandingOfficer;
        int bridgeLength;
        int bridgeWidth;
        float viewScreenBrightness;
        unsigned int numberOfTerminals;

        void showOnViewScreen(std::string view);
        int selfDestruct();
        float adjustViewScreenBrightness(float brightness);
    };
};

// Definitions for SaucerSection member functions
SaucerSection::SaucerSection()
    : attached(true), decks(10), shieldStrength(100.0f), shieldType("Standard"), personnelOnboard(1000)
{
}

SaucerSection::~SaucerSection()
{
    std::cout << "Destructing SaucerSection\n";
}

bool SaucerSection::detachSaucer()
{
    attached = false;
    std::cout << "Detaching saucer...\n";
    for (int i = 0; i < decks; ++i)
    {
        std::cout << "Detaching deck " << i + 1 << "...\n";
    }
    return attached;
}

float SaucerSection::firePhasers(int pattern, float power)
{
    std::cout << "Firing phasers with pattern " << pattern << " and power " << power << std::endl;
    for (int i = 0; i < 5; ++i)
    {
        power *= 0.9f;  // Reduce power with each iteration
        std::cout << "Power after firing " << i + 1 << ": " << power << std::endl;
    }
    return power;
}

float SaucerSection::raiseShields()
{
    const float maxShieldStrength = 110.0f; // Define the max shield strength
    for (int i = 0; i < 10; ++i)
    {
        if (shieldStrength < maxShieldStrength)
        {
            shieldStrength += 10.0f;
            if (shieldStrength > maxShieldStrength)
            {
                shieldStrength = maxShieldStrength;
            }
            std::cout << "Raising shields: " << shieldStrength << "%\n";
        }
    }
    return shieldStrength;
}

// Definitions for Bridge member functions
SaucerSection::Bridge::Bridge()
    : commandingOfficer("Captain"), bridgeLength(50), bridgeWidth(30), viewScreenBrightness(75.0f), numberOfTerminals(5)
{
}

SaucerSection::Bridge::~Bridge()
{
    std::cout << "Destructing Bridge\n";
}

void SaucerSection::Bridge::showOnViewScreen(std::string view)
{
    std::cout << "Displaying " << view << " on the view screen\n";
}

int SaucerSection::Bridge::selfDestruct()
{
    std::cout << "Initiating self-destruct sequence\n";
    for (int i = 10; i > 0; --i)
    {
        std::cout << "Self-destruct in " << i << " seconds\n";
    }
    return 0;
}

float SaucerSection::Bridge::adjustViewScreenBrightness(float brightness)
{
    const float tolerance = 0.01f; // Define a small tolerance
    while (std::fabs(viewScreenBrightness - brightness) > tolerance) // Use std::fabs here
    {
        if (viewScreenBrightness < brightness)
            viewScreenBrightness += 1.0f;
        else
            viewScreenBrightness -= 1.0f;
        std::cout << "Adjusting brightness: " << viewScreenBrightness << "\n";
    }
    return viewScreenBrightness;
}


/*
 copied UDT 2:
 */
struct WarpCoreReactor
{
    WarpCoreReactor();
    ~WarpCoreReactor();

    float maximumWarp;
    float currentWarp;
    int connectedNacelles;
    float reactorTemperature;
    std::string status;

    struct DilithiumMatrix
    {
        DilithiumMatrix();
        ~DilithiumMatrix();

        float dilithiumCapacity;
        float intermixRatio;
        bool matrixStability;
        int crystalCount;
        float matrixTemperature;

        float adjustIntermixRatio(float newRatio);
        bool replaceDilithiumCrystals(float newCapacity);
        void monitorMatrix();
    };

    void engageWarp(float warpFactor);
    void shutdownWarp();
    float getWarpEfficiency();
};

// Definitions for WarpCoreReactor member functions
WarpCoreReactor::WarpCoreReactor()
    : maximumWarp(9.9f), currentWarp(0.0f), connectedNacelles(2), reactorTemperature(300.0f), status("Operational")
{
}

WarpCoreReactor::~WarpCoreReactor()
{
    std::cout << "Destructing WarpCoreReactor\n";
}

void WarpCoreReactor::engageWarp(float warpFactor)
{
    currentWarp = warpFactor;
    std::cout << "Engaging warp to factor " << warpFactor << std::endl;
    for (int i = 0; i < 10; ++i)
    {
        currentWarp += 0.1f;
        reactorTemperature += 5.0f;
        std::cout << "Increasing warp speed: " << currentWarp << std::endl;
        std::cout << "Reactor temperature: " << reactorTemperature << " C\n";
    }
}

void WarpCoreReactor::shutdownWarp()
{
    std::cout << "Shutting down warp\n";
    while (currentWarp > 0.0f)
    {
        currentWarp -= 0.1f;
        reactorTemperature -= 5.0f;
        std::cout << "Decreasing warp speed: " << currentWarp << std::endl;
        std::cout << "Reactor temperature: " << reactorTemperature << " C\n";
    }
}

float WarpCoreReactor::getWarpEfficiency()
{
    float efficiency = (currentWarp / maximumWarp) * 100.0f;
    std::cout << "Warp efficiency: " << efficiency << "%\n";
    return efficiency;
}

// Definitions for DilithiumMatrix member functions
WarpCoreReactor::DilithiumMatrix::DilithiumMatrix()
    : dilithiumCapacity(100.0f), intermixRatio(1.0f), matrixStability(true), crystalCount(10), matrixTemperature(250.0f)
{
}

WarpCoreReactor::DilithiumMatrix::~DilithiumMatrix()
{
    std::cout << "Destructing DilithiumMatrix\n";
}

float WarpCoreReactor::DilithiumMatrix::adjustIntermixRatio(float newRatio)
{
    const float tolerance = 0.01f; // Define a small tolerance
    while (std::fabs(intermixRatio - newRatio) > tolerance) // Use std::fabs here
    {
        if (intermixRatio < newRatio)
            intermixRatio += 0.1f;
        else
            intermixRatio -= 0.1f;
        std::cout << "Adjusting intermix ratio: " << intermixRatio << "\n";
    }
    return intermixRatio;
}

bool WarpCoreReactor::DilithiumMatrix::replaceDilithiumCrystals(float newCapacity)
{
    for (int i = 0; i < crystalCount; ++i)
    {
        std::cout << "Replacing crystal " << i + 1 << "\n";
    }
    dilithiumCapacity = newCapacity;
    return true;
}

void WarpCoreReactor::DilithiumMatrix::monitorMatrix()
{
    for (int i = 0; i < 5; ++i)
    {
        std::cout << "Matrix stability: " << (matrixStability ? "Stable" : "Unstable") << "\n";
    }
}



/*
 copied UDT 3:
 */
struct WarpNacelle
{
    WarpNacelle();
    ~WarpNacelle();

    int nacelleID;
    float warpFieldStability;
    bool operational;
    int coilCount;
    float energyConsumption;

    struct WarpCoil
    {
        WarpCoil();
        ~WarpCoil();

        float coilInductance;
        float coilResistance;
        bool isActive;
        int coilID;
        float coilTemperature;

        void activateCoil();
        void deactivateCoil();
        float getCoilEfficiency();
    };

    void activateNacelle();
    void deactivateNacelle();
    float checkNacelleIntegrity();
};

// Definitions for WarpNacelle member functions
WarpNacelle::WarpNacelle()
    : nacelleID(1), warpFieldStability(100.0f), operational(true), coilCount(4), energyConsumption(500.0f)
{
}

WarpNacelle::~WarpNacelle()
{
    std::cout << "Destructing WarpNacelle\n";
}

void WarpNacelle::activateNacelle()
{
    const float maxWarpFieldStability = 110.0f; // Define the max warp field stability
    operational = true;
    std::cout << "Activating nacelle " << nacelleID << std::endl;
    for (int i = 0; i < 10; ++i)
    {
        if (warpFieldStability < maxWarpFieldStability)
        {
            warpFieldStability += 1.0f;
            if (warpFieldStability > maxWarpFieldStability)
            {
                warpFieldStability = maxWarpFieldStability;
            }
            energyConsumption += 10.0f;
            std::cout << "Increasing warp field stability: " << warpFieldStability << "%\n";
            std::cout << "Energy consumption: " << energyConsumption << " units\n";
        }
    }
}

void WarpNacelle::deactivateNacelle()
{
    operational = false;
    std::cout << "Deactivating nacelle " << nacelleID << std::endl;
    while (warpFieldStability > 0.0f)
    {
        warpFieldStability -= 1.0f;
        energyConsumption -= 10.0f;
        std::cout << "Decreasing warp field stability: " << warpFieldStability << "%\n";
        std::cout << "Energy consumption: " << energyConsumption << " units\n";
    }
}

float WarpNacelle::checkNacelleIntegrity()
{
    std::cout << "Checking nacelle integrity: " << warpFieldStability << "%\n";
    return warpFieldStability;
}

// Definitions for WarpCoil member functions
WarpNacelle::WarpCoil::WarpCoil()
    : coilInductance(0.0f), coilResistance(0.0f), isActive(false), coilID(1), coilTemperature(20.0f)
{
}

WarpNacelle::WarpCoil::~WarpCoil()
{
    std::cout << "Destructing WarpCoil\n";
}

void WarpNacelle::WarpCoil::activateCoil()
{
    const float maxCoilInductance = 110.0f; // Define the max coil inductance
    isActive = true;
    std::cout << "Activating coil\n";
    for (int i = 0; i < 5; ++i)
    {
        if (coilInductance < maxCoilInductance)
        {
            coilInductance += 10.0f;
            if (coilInductance > maxCoilInductance)
            {
                coilInductance = maxCoilInductance;
            }
            coilTemperature += 5.0f;
            std::cout << "Increasing coil inductance: " << coilInductance << " mH\n";
            std::cout << "Increasing coil temperature: " << coilTemperature << " C\n";
        }
    }
}

void WarpNacelle::WarpCoil::deactivateCoil()
{
    isActive = false;
    std::cout << "Deactivating coil\n";
    while (coilInductance > 0.0f)
    {
        coilInductance -= 10.0f;
        coilTemperature -= 5.0f;
        std::cout << "Decreasing coil inductance: " << coilInductance << " mH\n";
        std::cout << "Decreasing coil temperature: " << coilTemperature << " C\n";
    }
}

float WarpNacelle::WarpCoil::getCoilEfficiency()
{
    float efficiency = (coilInductance / coilResistance) * 100.0f;
    std::cout << "Coil efficiency: " << efficiency << "%\n";
    return efficiency;
}

/*
 new UDT 4:
 with 2 member functions
 */
struct GalaxyClassStarship
{
    GalaxyClassStarship();
    ~GalaxyClassStarship();

    SaucerSection mainSaucer;
    WarpCoreReactor coreReactor;
    WarpNacelle nacelle;

    void engageWarp(float speed);
    void scanForLifeForms();
    void activateCloakingDevice();
};

// Definitions for GalaxyClassStarship member functions
GalaxyClassStarship::GalaxyClassStarship()
{
}

GalaxyClassStarship::~GalaxyClassStarship()
{
    std::cout << "Destructing GalaxyClassStarship\n";
}

void GalaxyClassStarship::engageWarp(float speed)
{
    coreReactor.engageWarp(speed);
    std::cout << "Warp engaged to speed " << speed << std::endl;
}

void GalaxyClassStarship::scanForLifeForms()
{
    std::cout << "Scanning for life forms\n";
    for (int i = 0; i < 5; ++i)
    {
        std::cout << "Life form detected at sector " << i + 1 << std::endl;
    }
}

void GalaxyClassStarship::activateCloakingDevice()
{
    mainSaucer.raiseShields();
    std::cout << "Cloaking device activated\n";
    for (int i = 0; i < 10; ++i)
    {
        std::cout << "Cloaking in " << 10 - i << " seconds\n";
    }
}
/*
 new UDT 5:
 with 2 member functions
 */
struct ShuttlePod
{
    ShuttlePod();
    ~ShuttlePod();

    SaucerSection::Bridge shuttleBridge;
    WarpCoreReactor::DilithiumMatrix DilithiumMatrix;
    WarpNacelle WarpNacellePart;

    void setCourse(std::string destination);
    void dockWithStarship();
    void enableAutopilot();
};

// Definitions for ShuttlePod member functions
ShuttlePod::ShuttlePod()
{
}

ShuttlePod::~ShuttlePod()
{
    std::cout << "Destructing ShuttlePod\n";
}

void ShuttlePod::setCourse(std::string destination)
{
    std::cout << "Setting course to " << destination << std::endl;
    for (int i = 0; i < 10; ++i)
    {
        WarpNacellePart.activateNacelle();
        std::cout << "Course set. Increasing speed to reach " << destination << std::endl;
    }
}

void ShuttlePod::dockWithStarship()
{
    std::cout << "Docking with starship\n";
    while (WarpNacellePart.warpFieldStability > 0.0f)
    {
        WarpNacellePart.deactivateNacelle();
        std::cout << "Decreasing speed for docking\n";
    }
}

void ShuttlePod::enableAutopilot()
{
    shuttleBridge.adjustViewScreenBrightness(100.0f);
    DilithiumMatrix.adjustIntermixRatio(1.5f);
    std::cout << "Autopilot enabled\n";
    for (int i = 0; i < 10; ++i)
    {
        std::cout << "Autopilot system check " << i + 1 << std::endl;
    }
}


/*
 MAKE SURE YOU ARE NOT ON THE MASTER BRANCH

 Commit your changes by clicking on the Source Control panel on the left, entering a message, and click [Commit and push].
 
 If you didn't already: 
    Make a pull request after you make your first commit
    pin the pull request link and this repl.it link to our DM thread in a single message.

 send me a DM to review your pull request when the project is ready for review.

 Wait for my code review.
 */

#include <iostream>
int main()
{

    // Instantiate UDTs from step 4
    GalaxyClassStarship enterprise;
    ShuttlePod galileo;

    // Call their member functions
    enterprise.engageWarp(9.5f);
    enterprise.scanForLifeForms();
    enterprise.activateCloakingDevice();

    galileo.setCourse("Mars");
    galileo.dockWithStarship();
    galileo.enableAutopilot();
    
    std::cout << "good to go!" << std::endl;
}
