
#ifndef CL2_H
#define CL2_H


/**
  * class Cl2
  * 
  */

class Cl2
{
public:
  // Constructors/Destructors
  //  


  /**
   * Empty Constructor
   */
  Cl2();

  /**
   * Empty Destructor
   */
  virtual ~Cl2();

  // Static Public attributes
  //  

  // Public attributes
  //  


  // Public attribute accessor methods
  //  


  // Public attribute accessor methods
  //

protected:
  // Static Protected attributes
  //  

  // Protected attributes
  //  


  // Protected attribute accessor methods
  //  


  // Protected attribute accessor methods
  //

private:
  // Static Private attributes
  //  

  // Private attributes
  //  

  Cl3* new_attribute;

  // Private attribute accessor methods
  //  


  // Private attribute accessor methods
  //  


  /**
   * Set the value of new_attribute
   * @param value the new value of new_attribute
   */
  void setNew_attribute(Cl3* value)
  {
    new_attribute = value;
  }

  /**
   * Get the value of new_attribute
   * @return the value of new_attribute
   */
  Cl3* getNew_attribute()
  {
    return new_attribute;
  }

  void initAttributes();

};

#endif // CL2_H
