package validator.validator;

import validator.domain.Person;

public class PersonValidator {
//    public void validate(Person person){
//        if(validateName(person.getFirstName()) && validateName(person.getLastName())){
//            System.out.println("Valid person");
//        }
//        else{
//            System.out.println("Invalid person");
//        }
//    }

    public void validate(Person person){
        if(validateNameRegex(person.getFirstName()) &&
            validateNameRegex(person.getLastName()) &&
            validateMobilePhoneNumber(person.getPhoneNumber()) &&
            validateAge(person.getAge())){
            System.out.println("Valid person");
        }
        else{
            System.out.println("Invalid person");
        }
    }

    private boolean validateName(String name){
        if(name.isEmpty() || name.isBlank()) {
            return false;
        }
        return Character.isUpperCase(name.charAt(0));
    }

    private boolean validateNameRegex(String name){
        String regex = "[A-Z][a-z]+";
        return name.matches(regex);
    }

    private boolean validateMobilePhoneNumber(String phoneNumber){
        return phoneNumber.matches("(07)[0-9]{8}");
    }

    private boolean validateAge(int age){
        if(age < 18)
            return false;
        return true;
    }

    public String validateWithErrorMessages(Person person)
    {
        StringBuilder result = new StringBuilder();

        if (!validateNameRegex(person.getFirstName()) || !validateNameRegex(person.getLastName())){
            result.append(Error.INVALID_NAME + ", ");
        }
        if(!validateMobilePhoneNumber(person.getPhoneNumber())){
            result.append(Error.INVALID_PHONE_NUMBER + ", ");
        }
        if(!validateAge(person.getAge())){
            result.append(Error.TOO_YOUNG);
        }
        return result.length() == 0 ? "Valid person" : result.toString();
    }

}
