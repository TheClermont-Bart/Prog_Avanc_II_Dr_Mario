let project = new Project("DrMario");

project.cppStd = "c++11";

await project.addProject("./Prog_Avanc_II_Engine");

project.addFiles("Prog_Avanc_II_DrMario/Sources/**");
project.addIncludeDir("./Prog_Avanc_II_Engine/Includes/**");
project.addFiles("Prog_Avanc_II_DrMario/Includes/**");

project.setDebugDir("Deployment");

project.flatten();

resolve(project);   
